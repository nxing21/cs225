if(EXISTS "/workspaces/bradsol/release 10/build/test_tests-b12d07c.cmake")
  include("/workspaces/bradsol/release 10/build/test_tests-b12d07c.cmake")
else()
  add_test(test_NOT_BUILT-b12d07c test_NOT_BUILT-b12d07c)
endif()