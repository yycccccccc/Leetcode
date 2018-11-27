题意：
买卖游戏，返回可以得到的最大的点数。
思路：
1.首先将数组排序，这样硬币的价值就会由小到大排列。
2.题目中的要求是当有足够多的钱的时候，可以减少钱数使点数+1；如果点数大于一，可以通过减少点数来使手中的钱增多。
本题的目标是拥有最多的点数，因此需要用钱换点数，买最便宜的卖掉最贵的。
3.设立两个指针一个指向头部一个指向尾部。当有钱的时候，用最少的钱买点；当没有钱的时候，用一个点来买最多的钱，即尾部元素。
如果没钱没点，那么退出。
4.记录下过程中可能获得的最大的点数，返回。
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int ret = 0;
        int point = 0;
        int i = 0;
        int j = tokens.size()-1;
        while(i <= j){
            if(P >= tokens[i]){
                ++point;
                P -= tokens[i];
                ret = max(ret,point);
                ++i;
            }
            else if(point >= 1){
                --point;
                P += tokens[j];
                --j;
            }else{
                break;
            }
        }
        return ret;
    }
};
补充：贪心算法
1.首先注意贪心策略的应用场景：
贪心算法是指，在对问题求解时，总是做出在当前看来是最好的选择。
也就是说，不从整体最优上加以考虑，所做出的仅是在某种意义上的局部最优解。
贪心算法不是对所有问题都能得到整体最优解，选择的贪心策略必须具备无后效性，即某个状态以后的过程不会影响以前的状态，只与当前状态有关。
所以对所采用的贪心策略一定要仔细分析其是否满足无后效性。
2.基本思路：
>建立数学模型来描述问题。
>把求解的问题分成若干个子问题。
>对每一子问题求解，得到子问题的局部最优解。
>把子问题的解局部最优解合成原来解问题的一个解。
3.框架
从问题的某一初始解出发；
    while （能朝给定总目标前进一步）
    { 
          利用可行的决策，求出可行解的一个解元素；
    }
由所有解元素组合成问题的一个可行解；