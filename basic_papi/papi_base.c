#include <papi_test.h>

#if defined(_WIN32)
#define OUT_FMT		"%12d\t%12I64d\t%12I64d\t%.2f\n"
#else
#define OUT_FMT		"%12d\t%12lld\t%12lld\t%.2f\n"
#endif

#define array_size(a) sizeof(a)/sizeof(a[0])

int test();
int warmup();

int
main( int argc, char **argv )
{
	int retval, i, j = 0;
	int EventSet = PAPI_NULL;
	long long values[2];
	const PAPI_hw_info_t *hwinfo = NULL;
	char descr[PAPI_MAX_STR_LEN];
	PAPI_event_info_t evinfo;
	PAPI_mh_level_t *L;


	const int eventlist[] = {
      /*
        */
		PAPI_L1_DCA,
		PAPI_L1_DCM,
		PAPI_L1_DCH,
		PAPI_L2_DCA,
		PAPI_L2_DCM,
		PAPI_L2_DCH,
        PAPI_L3_DCA,
        PAPI_L3_TCM,
        PAPI_L3_LDM,
        PAPI_LST_INS,
        PAPI_LD_INS,
        PAPI_SR_INS,
        PAPI_TOT_CYC,
        PAPI_TLB_DM,
        PAPI_RES_STL,
        PAPI_TOT_IIS,
        PAPI_TOT_INS,
		0
	};

    int arr_size = array_size(eventlist) - 1;
    double info[arr_size];

    for (i = 0; i < arr_size; i++)
      info[i] = 0;

	tests_quiet( argc, argv );	/* Set TESTS_QUIET variable */

	if ( ( retval =
		   PAPI_library_init( PAPI_VER_CURRENT ) ) != PAPI_VER_CURRENT )
		test_fail( __FILE__, __LINE__, "PAPI_library_init", retval );

	if ( ( hwinfo = PAPI_get_hardware_info(  ) ) == NULL ) {
		test_fail( __FILE__, __LINE__, "PAPI_get_hardware_info", 2 );
	}

	if ( ( retval = PAPI_create_eventset( &EventSet ) ) != PAPI_OK )
		test_fail( __FILE__, __LINE__, "PAPI_create_eventset", retval );

	/* Extract and report the cache information */
	L = ( PAPI_mh_level_t * ) ( hwinfo->mem_hierarchy.level );
	for ( i = 0; i < hwinfo->mem_hierarchy.levels; i++ ) {
		for ( j = 0; j < 2; j++ ) {
			int tmp;

			tmp = PAPI_MH_CACHE_TYPE( L[i].cache[j].type );
			if ( tmp == PAPI_MH_TYPE_UNIFIED ) {
				printf( "L%d Unified ", i + 1 );
			} else if ( tmp == PAPI_MH_TYPE_DATA ) {
				printf( "L%d Data ", i + 1 );
			} else if ( tmp == PAPI_MH_TYPE_INST ) {
				printf( "L%d Instruction ", i + 1 );
			} else if ( tmp == PAPI_MH_TYPE_VECTOR ) {
				printf( "L%d Vector ", i + 1 );
			} else if ( tmp == PAPI_MH_TYPE_TRACE ) {
				printf( "L%d Trace ", i + 1 );
			} else if ( tmp == PAPI_MH_TYPE_EMPTY ) {
				break;
			} else {
				test_fail( __FILE__, __LINE__, "PAPI_get_hardware_info",
						   PAPI_EBUG );
			}

			tmp = PAPI_MH_CACHE_WRITE_POLICY( L[i].cache[j].type );
			if ( tmp == PAPI_MH_TYPE_WB ) {
				printf( "Write back " );
			} else if ( tmp == PAPI_MH_TYPE_WT ) {
				printf( "Write through " );
			} else {
				test_fail( __FILE__, __LINE__, "PAPI_get_hardware_info",
						   PAPI_EBUG );
			}

			tmp = PAPI_MH_CACHE_REPLACEMENT_POLICY( L[i].cache[j].type );
			if ( tmp == PAPI_MH_TYPE_PSEUDO_LRU ) {
				printf( "Pseudo LRU policy " );
			} else if ( tmp == PAPI_MH_TYPE_LRU ) {
				printf( "LRU policy " );
			} else if ( tmp == PAPI_MH_TYPE_UNKNOWN ) {
				printf( "Unknown policy " );
			} else {
				test_fail( __FILE__, __LINE__, "PAPI_get_hardware_info",
						   PAPI_EBUG );
			}

			printf( "Cache:\n" );
			if ( L[i].cache[j].type ) {
				printf
					( "  Total size: %dKB\n  Line size: %dB\n  Number of Lines: %d\n  Associativity: %d\n\n",
					  ( L[i].cache[j].size ) >> 10, L[i].cache[j].line_size,
					  L[i].cache[j].num_lines, L[i].cache[j].associativity );
			}
		}
	}

	for ( i = 0; eventlist[i] != 0; i++ ) {
		PAPI_event_code_to_name( eventlist[i], descr );
		if ( PAPI_add_event( EventSet, eventlist[i] ) != PAPI_OK )
			continue;

		if ( PAPI_get_event_info( eventlist[i], &evinfo ) != PAPI_OK )
			test_fail( __FILE__, __LINE__, "PAPI_get_event_info", retval );

		printf( "\nEvent: %s\nShort: %s\nLong: %s\n\n",
				evinfo.symbol, evinfo.short_descr, evinfo.long_descr );
		printf( "       Bytes\t\tCold\t\tWarm\tPercent\n" );

		if ( ( retval = PAPI_start( EventSet ) ) != PAPI_OK )
			test_fail( __FILE__, __LINE__, "PAPI_start", retval );

        warmup();

        if ( ( retval = PAPI_reset( EventSet ) ) != PAPI_OK )
          test_fail( __FILE__, __LINE__, "PAPI_reset", retval );

        test();

        if ( ( retval = PAPI_read( EventSet, &values[0] ) ) != PAPI_OK )
          test_fail( __FILE__, __LINE__, "PAPI_read", retval );
        if ( ( retval = PAPI_reset( EventSet ) ) != PAPI_OK )
          test_fail( __FILE__, __LINE__, "PAPI_reset", retval );

        test();

        if ( ( retval = PAPI_read( EventSet, &values[1] ) ) != PAPI_OK )
          test_fail( __FILE__, __LINE__, "PAPI_read", retval );

        printf( OUT_FMT, j, values[0], values[1],
            ( ( float ) values[1] /
              ( float ) ( ( values[0] !=
                  0 ) ? values[0] : 1 ) * 100.0 ) );

        if ( ( retval = PAPI_stop( EventSet, NULL ) ) != PAPI_OK )
          test_fail( __FILE__, __LINE__, "PAPI_stop", retval );

        if ( ( retval =
              PAPI_remove_event( EventSet, eventlist[i] ) ) != PAPI_OK )
          test_fail( __FILE__, __LINE__, "PAPI_remove_event", retval );

        info[i] =  (values[0]/2 + values[1]/2);
    }

    for (i = 0; i < arr_size; i++)
    {
		if ( PAPI_get_event_info( eventlist[i], &evinfo ) != PAPI_OK )
			test_fail( __FILE__, __LINE__, "PAPI_get_event_info", retval );
		printf( "Event: %s\tShort: %s\t\t\t\t",
				evinfo.symbol, evinfo.short_descr );
        printf(" %e\n", info[i]);
    }

    if ( ( retval = PAPI_destroy_eventset( &EventSet ) ) != PAPI_OK )
      test_fail( __FILE__, __LINE__, "PAPI_destroy_eventset", retval );

    test_pass( __FILE__, NULL, 0 );

    exit( 1 );
}
