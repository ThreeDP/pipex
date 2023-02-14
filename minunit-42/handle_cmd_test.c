#include "minunit.h"
#include "../srcs/pipex.h"
#include <stdio.h>

MU_TEST(passing_the_command_echo_test_should_be_echo_noprint_test)
{
    // ARRANGE
    char    cmd[] = "echo test";
    char    *expected_string = "echo\atest";

    // ACT 
    handle_cmd(cmd);

    // ASSERT
    mu_assert_string_eq(expected_string, cmd);
}

// sq = simple quotes
MU_TEST(passing_the_command_echo_sq_test_space_word_sq_should_be_echo_noprint_sq_test_space_word_sq)
{
    // ARRANGE
    char    cmd[] = "echo 'test word'";
    char    *expected_string = "echo\a'test word'";

    // ACT 
    handle_cmd(cmd);

    // ASSERT
    mu_assert_string_eq(expected_string, cmd);
}

// dq = double quotes
MU_TEST(passing_the_command_echo_dq_test_space_word_dq_should_be_echo_noprint_dq_test_space_word_dq)
{
    // ARRANGE
    char    cmd[] = "echo \"test word\"";
    char    *expected_string = "echo\a\"test word\"";

    // ACT 
    handle_cmd(cmd);

    // ASSERT
    mu_assert_string_eq(expected_string, cmd);
}

//  bq = bar quotes
// bks = backslash
MU_TEST(passing_the_command_should_be_sed_noprint_s_bks_go_bks_bq_noprint_test_noprint_bq_bks_g)
{
    // ARRANGE
    char    cmd[] = "sed s/go/\\\' test \\\'/g";
    char    *expected_string = "sed\as/go/\\\'\atest\a\\\'/g";

    // ACT 
    handle_cmd(cmd);

    // ASSERT
    mu_assert_string_eq(expected_string, cmd);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(passing_the_command_echo_test_should_be_echo_noprint_test);
    MU_RUN_TEST(passing_the_command_echo_sq_test_space_word_sq_should_be_echo_noprint_sq_test_space_word_sq);
    MU_RUN_TEST(passing_the_command_echo_dq_test_space_word_dq_should_be_echo_noprint_dq_test_space_word_dq);
    MU_RUN_TEST(passing_the_command_should_be_sed_noprint_s_bks_go_bks_bq_noprint_test_noprint_bq_bks_g);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

