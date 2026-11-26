class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool aliceTurn = true;

        while (n >= stones) {

            n -= stones;

            aliceTurn = !aliceTurn;
            stones--;
        }

        // The player whose turn it is cannot move
        return !aliceTurn;
        
    }
};