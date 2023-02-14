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

MU_TEST(passing_echo_test_should_be_echo_backslash_a_test)
{
    // ARRANGE
    char        cmd_sent[]      = "cut test";
    char        cmd_expected[]  = "cut\atest";

    // ACT
    handle_cmd(cmd_sent);

    // ASSERT
    mu_assert_string_eq(cmd_expected, cmd_sent);
}

MU_TEST(passing_cut_minus_d_backslash_single_quote_space_single_quote_should_be_cut_bks_a_minus_d_bkl_sq_space_sq)
{
    // ARRANGE
    char        cmd_sent[]      = "cut -d\' \'";
    char        cmd_expected[]  = "cut\a-d' '";

    // ACT
    handle_cmd(cmd_sent);

    // ASSERT
    mu_assert_string_eq(cmd_expected, cmd_sent);
}

MU_TEST(passing_the_command_wc_space_minus_l_should_be_wc_backslash_a_minus_l)
{
    // ARRANGE
    char        cmd_sent[]      = "wc -l";
    char        cmd_expected[]  = "wc\a-l";

    // ACT
    handle_cmd(cmd_sent);

    // ASSERT
    mu_assert_string_eq(cmd_expected, cmd_sent);
}

MU_TEST(passing_a_command_with_two_single_quote_and_one_letter_close_should_be_cut_backslash_a_minus_d_single_quote_space_single_quote)
{
    // ARRANGE
    char        cmd_sent[]      = "cut -d' ' -f2";
    char        cmd_expected[]  = "cut\a-d' '\a-f2";

    // ACT
    handle_cmd(cmd_sent);

    // ASSERT
    mu_assert_string_eq(cmd_expected, cmd_sent);
}

MU_TEST(test_passing_with_spaces_and_single_quotes_must_be_backslash_a_nodes_minus_spaces_between_single_quotes)
{
    // ARRANGE
    char        cmd_sent[]      = "cut -d' ' -f2";
    char        cmd_expected[]  = "cut\a-d' '\a-f2";

    // ACT
    handle_cmd(cmd_sent);

    // ASSERT
    mu_assert_string_eq(cmd_expected, cmd_sent);
}

MU_TEST(test_passing_with_spaces_and_quotes_must_be_backslash_a_nodes_minus_spaces_between_quotes)
{
    // ARRANGE
    char        cmd_sent[]      = "cut -d\" \" -f2";
    char        cmd_expected[]  = "cut\a-d\" \"\a-f2";

    // ACT
    handle_cmd(cmd_sent);

    // ASSERT
    mu_assert_string_eq(cmd_expected, cmd_sent);
}

MU_TEST(test_passing_a_echo_command_with_single_quotes)
{
    // ARRANGE
    char        cmd_sent[]      = "echo 'Tem um abacate no meu código'";
    char        cmd_expected[]  = "echo\a'Tem um abacate no meu código'";

    // ACT
    handle_cmd(cmd_sent);

    // ASSERT
    mu_assert_string_eq(cmd_expected, cmd_sent);
}

MU_TEST(test_passing_a_echo_command_with_quotes)
{
    // ARRANGE
    char        cmd_sent[]      = "echo \"Tem um abacate no meu código\"";
    char        cmd_expected[]  = "echo\a\"Tem um abacate no meu código\"";
    
    // ACT
    handle_cmd(cmd_sent);

    // ASSERT
    mu_assert_string_eq(cmd_expected, cmd_sent);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(passing_the_command_echo_test_should_be_echo_noprint_test);
    MU_RUN_TEST(passing_the_command_echo_sq_test_space_word_sq_should_be_echo_noprint_sq_test_space_word_sq);
    MU_RUN_TEST(passing_the_command_echo_dq_test_space_word_dq_should_be_echo_noprint_dq_test_space_word_dq);
    MU_RUN_TEST(passing_the_command_should_be_sed_noprint_s_bks_go_bks_bq_noprint_test_noprint_bq_bks_g);
    MU_RUN_TEST(passing_echo_test_should_be_echo_backslash_a_test);
    MU_RUN_TEST(passing_cut_minus_d_backslash_single_quote_space_single_quote_should_be_cut_bks_a_minus_d_bkl_sq_space_sq);
    MU_RUN_TEST(passing_the_command_wc_space_minus_l_should_be_wc_backslash_a_minus_l);
    MU_RUN_TEST(passing_a_command_with_two_single_quote_and_one_letter_close_should_be_cut_backslash_a_minus_d_single_quote_space_single_quote);
    MU_RUN_TEST(test_passing_with_spaces_and_single_quotes_must_be_backslash_a_nodes_minus_spaces_between_single_quotes);
    MU_RUN_TEST(test_passing_with_spaces_and_quotes_must_be_backslash_a_nodes_minus_spaces_between_quotes);
    MU_RUN_TEST(test_passing_a_echo_command_with_single_quotes);
    MU_RUN_TEST(test_passing_a_echo_command_with_quotes);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

