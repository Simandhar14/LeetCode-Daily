class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk=0;
        int empty=0;
        while(numBottles>0)
        {
            drunk+=numBottles;
            empty+=numBottles;
            numBottles=0;
            while(empty>=numExchange)
            {
                numBottles++;
                empty-=numExchange;
                numExchange++;
            }
        }
        return drunk;
    }
};
