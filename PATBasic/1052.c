/**
 * 1052. 卖个萌 (20)
 * 
 * 萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情
 * 符号是按下列格式输出的：
 * 
 * [左手]([左眼][口][右眼])[右手]
 * 现给出可选用的符号集合，请你按用户的要求输出表情。
 * 
 * 输入格式：
 * 
 * 输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。
 * 题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。
 * 
 * 之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，
 * 顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），
 * 数字间以空格分隔。
 * 
 * 输出格式：
 * 
 * 对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出
 * “Are you kidding me? @\/@”。
 * 
 * 输入样例：
 * [╮][╭][o][~\][/~]  [<][>]
 *  [╯][╰][^][-][=][>][<][@][⊙]
 * [Д][▽][_][ε][^]  ...
 * 4
 * 1 1 2 2 2
 * 6 8 1 5 5
 * 3 3 4 3 3
 * 2 10 3 9 3
 * 输出样例：
 * ╮(╯▽╰)╭
 * <(@Д=)/~
 * o(^ε^)o
 * Are you kidding me? @\/@
 */
#include <stdio.h>
/* https://en.wikipedia.org/wiki/Variable-width_encoding */
int main()
{
    char c, symbols[3][10][13] = {0};
    for(int symbol = 0; symbol < 3; symbol++)
    {
        int i, index = 0;
        while((c = getchar()) != '\n') if(c == '[')
        {
            
            for(i = 0; (c = getchar()) != ']'; i++)
                symbols[symbol][index][i] = c;
            symbols[symbol][index++][i] = '\0';
        }
    }
    
    int N, m[5];
    char msg[] = "Are you kidding me? @\\/@";
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int i = 0; i < 5; i++)  scanf("%d", m + i);
        if(symbols[0][m[0] - 1][0] && 
            symbols[1][m[1] - 1][0] && 
            symbols[2][m[2] - 1][0] && 
            symbols[1][m[3] - 1][0] && 
            symbols[0][m[4] - 1][0])
            printf("%s(%s%s%s)%s\n", symbols[0][m[0] - 1], symbols[1][m[1] - 1], 
                symbols[2][m[2] - 1], symbols[1][m[3] - 1], symbols[0][m[4] - 1]);
        else
            puts(msg);
    }
    
    return 0;
}
