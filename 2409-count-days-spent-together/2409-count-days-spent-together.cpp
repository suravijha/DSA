class Solution {
private:
    int calculate(string& day, vector<int>& prefix) {
        int month = stoi(day.substr(0, 2));
        int date = stoi(day.substr(3));

        return prefix[month - 1] + date;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefix(1, 0);

        for (int m: months) {
            prefix.push_back(prefix.back() + m);
        }

        int arrive1 = calculate(arriveAlice, prefix);
        int leave1 = calculate(leaveAlice, prefix);

        int arrive2 = calculate(arriveBob, prefix);
        int leave2 = calculate(leaveBob, prefix);

        return max(0, min(leave2, leave1) - max(arrive1, arrive2) + 1);
    }
};