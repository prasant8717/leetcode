/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int *stk = (int *)malloc(sizeof(int) * asteroidsSize);
    int top = -1;
    for (int i = 0; i < asteroidsSize; ++i)
    {
        if (top == -1)
        {
            top ++;
            stk[top] = asteroids[i];
        }
        else
        {
            if ((asteroids[i] > 0) && (stk[top] > 0))
            {
                top ++;
                stk[top] = asteroids[i];
            }
            else if ((asteroids[i] < 0) && (stk[top] < 0))
            {
                top ++;
                stk[top] = asteroids[i];
            }
            else if ((asteroids[i] > 0) && (stk[top] < 0))
            {
                top ++;
                stk[top] = asteroids[i];
            }
            else
            {
                while (1)
                {
                    if (abs(asteroids[i]) > stk[top])
                    {
                        stk[top] = asteroids[i];
                    }
                    else if (abs(asteroids[i]) == stk[top])
                    {
                        top --;
                    }
                    if (top <= 0)
                    {
                        break;
                    }
                    if ((stk[top] < 0) && (stk[top - 1] > 0))
                    {
                        top --;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    *returnSize = top + 1;
    return stk;
}
