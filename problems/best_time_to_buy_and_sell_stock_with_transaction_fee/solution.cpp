class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int bestPriceToBuy = 10000000;
        int bestPriceToSell = 0;
        int totalProfit = 0;

        for (auto price: prices) {
            if (price + fee < bestPriceToSell) {
                totalProfit += bestPriceToSell - bestPriceToBuy;
                bestPriceToBuy = 10000000;
                bestPriceToSell = 0;
            }
            if (price + fee < bestPriceToBuy) {
                bestPriceToBuy = price + fee;
            }
            if ((price > bestPriceToSell) && (price - bestPriceToBuy > 0)) {
                bestPriceToSell = price;
            }
        }

        if (bestPriceToSell - bestPriceToBuy > 0) {
            totalProfit += bestPriceToSell - bestPriceToBuy;
        }

        return totalProfit;
    }
};