#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// バブルソート(引数が不適切であればfalseを返す)
bool bubble_sort(item* begin, const item* end)
{
    // 1. 引数の不適切チェック
    if (begin == nullptr || end == nullptr || begin > end) {
        return false;
    }

    // 要素数を計算
    int n = static_cast<int>(end - begin);

    // 要素が0個または1個の場合はソート不要
    if (n < 2) {
        return true;
    }

    // 2. バブルソートの実装
    for (int i = 0; i < n - 1; i++) {
        for (item* p = begin; p < (end - 1 - i); p++) {
            // 【ここがポイント】
            // key を比較して、左の方が大きければ入れ替える（昇順）
            if (p->key > (p + 1)->key) {
                // 構造体の中身（keyも文字列も）を丸ごと入れ替え
                item temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
        }
    }

    // 最後に true を返すことで、テスト側に「成功」を伝えます
    return true;
}