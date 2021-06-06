int findPosition(int N) {
    if (N == 0)
        return -1;

    int position = 0;
    int tempPos = 0;
    while (N) {
        tempPos += 1;
        if (N & 1) {
            if (position)
                return -1;
            position = tempPos;
        }
        N /= 2;
    }

    return position == 0 ? -1 : position;
}