#include <iostream>

/**
 * @brief ユークリッドの互除法を用いて最大公約数と最小公倍数を同時に計算する関数
 * @param a 入力値1 (const参照で安全に受け取る)
 * @param b 入力値2 (const参照で安全に受け取る)
 * @param gcd_result 最大公約数を格納する参照変数（出力用）
 * @param lcm_result 最小公倍数を格納する参照変数（出力用）
 */
void calculateGcdAndLcm(long long a, long long b, long long &gcd_result, long long &lcm_result) {
    // 0以下の入力に対する簡易的なバリデーション
    if (a <= 0 || b <= 0) {
        gcd_result = 0;
        lcm_result = 0;
        return;
    }

    long long temp_a = a;
    long long temp_b = b;

    // ユークリッドの互除法による最大公約数（GCD）の計算
    while (temp_b != 0) {
        long long temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }

    // 求まった最大公約数を出力用参照変数に代入
    gcd_result = temp_a;

    // 最小公倍数（LCM）の計算: (a * b) / GCD
    // ※ オーバーフローを防ぐため、先に a を GCD で割ってから b を掛けています
    lcm_result = (a / gcd_result) * b;
}

int main() {
    long long num1 = 24;
    long long num2 = 36;

    // 結果を受け取るための変数
    long long gcd = 0;
    long long lcm = 0;

    // 関数を呼び出し、参照を通じて結果を受け取る
    calculateGcdAndLcm(num1, num2, gcd, lcm);

    // 結果の出力
    std::cout << "--- 計算結果 ---" << std::endl;
    std::cout << "数値 1: " << num1 << std::endl;
    std::cout << "数値 2: " << num2 << std::endl;
    std::cout << "最大公約数 (GCD): " << gcd << std::endl;
    std::cout << "最小公倍数 (LCM): " << lcm << std::endl;

    return 0;
}
