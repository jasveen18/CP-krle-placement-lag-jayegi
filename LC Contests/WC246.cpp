/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 1903. Largest Odd Number in String
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') & 1) {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};


// 2. 1904. The Number of Full Rounds You Have Played
class Solution {
public:
    int numberOfRounds(string startTime, string endTime) {
        // Convert date and time to time.
        int startHr = (startTime[0] - '0') * 10 + (startTime[1] - '0');
        int startMin = (startTime[3] - '0') * 10 + (startTime[4] - '0');
        int endHr = (endTime[0] - '0') * 10 + (endTime[1] - '0');
        int endMin = (endTime[3] - '0') * 10 + (endTime[4] - '0');

        if (endHr - startHr == 0 and (endMin - startMin) < 15 and (endMin - startMin) >= 0)
            return 0;

        // Take ceil and floor of start time and end time resp.
        if (startMin > 0 and startMin < 15)
            startMin = 15;
        else if (startMin > 15 and startMin < 30)
            startMin = 30;
        else if (startMin > 30 and startMin < 45)
            startMin = 45;
        else if (startMin > 45 and startMin < 60) {
            startMin = 0;
            startHr += 1;

            // Case of midnight
            if (startHr == 24)
                startHr = 0;
        }

        if (endMin > 0 and endMin < 15)
            endMin = 0;
        else if (endMin > 15 and endMin < 30)
            endMin = 15;
        else if (endMin > 30 and endMin < 45)
            endMin = 30;
        else if (endMin > 45 and endMin < 60)
            endMin = 45;

        // Now, I want to count the intervals.
        int intervals = 0;
        while (startHr != endHr or startMin != endMin) {
            startMin += 15;
            if (startMin == 60) {
                startMin = 0;
                startHr += 1;

                if (startHr == 24)
                    startHr = 0;
            }
            intervals++;
        }

        return intervals;
    }
};