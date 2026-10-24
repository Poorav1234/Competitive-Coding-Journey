class Solution {
public:
    int DayNumber(int month, int day){
        int actualDay = 0, i = 1;
        while(month > i){
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) actualDay += 31;
            else if(i == 2) actualDay += 28;
            else actualDay += 30;
            i++;
        }
        return actualDay + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveA_Month = stoi(arriveAlice.substr(0, 2));
        int arriveB_Month = stoi(arriveBob.substr(0, 2));
        int leaveA_Month = stoi(leaveAlice.substr(0, 2));
        int leaveB_Month = stoi(leaveBob.substr(0, 2));

        int arriveA_Day = stoi(arriveAlice.substr(3, 2));
        int arriveB_Day = stoi(arriveBob.substr(3, 2));
        int leaveA_Day = stoi(leaveAlice.substr(3, 2));
        int leaveB_Day = stoi(leaveBob.substr(3, 2));

        int arrive_alice = DayNumber(arriveA_Month, arriveA_Day);
        int arrive_bob = DayNumber(arriveB_Month, arriveB_Day);
        int leave_alice = DayNumber(leaveA_Month, leaveA_Day);
        int leave_bob = DayNumber(leaveB_Month, leaveB_Day);

        if(arrive_bob > leave_alice || arrive_alice > leave_bob) return 0;

        return min(leave_alice, leave_bob) - max(arrive_alice, arrive_bob) + 1;
    }
};