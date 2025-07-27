int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int gsum = 0;
    int csum = 0;
    for (int i = 0; i < gasSize; ++ i) {
        gsum += gas[i];
        csum += cost[i];
    }
    if (gsum < csum)
      return -1;
    int start = 0;
    int sum = 0;
    for (int i = 0; i < gasSize; ++i) {
      sum += gas[i] - cost[i];
      if (sum < 0) {
        sum = 0;
        start = i + 1;
      }
    }
    return start;
}
