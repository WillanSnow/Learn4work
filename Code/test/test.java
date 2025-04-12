public class income_tax {
    int tax_level = 5;
    int base_income = 1600;
    int[] level_limit = {500, 2000, 5000, 20000};
    int[] level_rate = {5, 10, 15, 20, 25};

    /**
     * Calculate the income tax based on the given income.
     *
     * @param  income  the income for which to calculate the tax
     * @return         the calculated income tax
     */
    double cauculate_income_tax(int income) {
        if (income < base_income) return 0;
        else {
            for (int i = 0; i<tax_level-1; i++) {

            }
        }
    }
}
