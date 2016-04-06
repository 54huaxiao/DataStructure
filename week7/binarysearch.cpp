template <typename T>
int binarySearch(const vector<T> table, int bot, int top, const T &x)
{
    int mid;
    while (top > bot) {
        mid = (top + bot) / 2;
        if (table[mid] < x) bot = mid + 1;
        else top = mid;
    }
    if (top < bot) return -1;
    else {
        if (table[bot] == x) {
            while (table[bot + 1] == x) bot++;
            return bot;
        }
        else return -1;
    }
}                                 