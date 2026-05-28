class LFUCache {
public:

    int cap;
    int minFreq;

    unordered_map<int, pair<int,int>> keyValueFreq;

    unordered_map<int, list<int>> freqList;

    unordered_map<int, list<int>::iterator> keyIter;

    LFUCache(int capacity) {

        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {

        int value = keyValueFreq[key].first;
        int freq = keyValueFreq[key].second;

        // remove key from old freq list
        freqList[freq].erase(keyIter[key]);

        // if old freq list empty
        if(freqList[freq].empty()) {

            freqList.erase(freq);

            if(minFreq == freq) {
                minFreq++;
            }
        }

        // increase freq
        freq++;

        keyValueFreq[key] = {value, freq};

        // insert into new freq list
        freqList[freq].push_front(key);

        keyIter[key] = freqList[freq].begin();
    }

    int get(int key) {

        if(keyValueFreq.find(key) == keyValueFreq.end()) {
            return -1;
        }

        updateFreq(key);

        return keyValueFreq[key].first;
    }

    void put(int key, int value) {

        if(cap == 0) {
            return;
        }

        // key exists
        if(keyValueFreq.find(key) != keyValueFreq.end()) {

            keyValueFreq[key].first = value;

            updateFreq(key);

            return;
        }

        // cache full
        if(keyValueFreq.size() == cap) {

            int keyToDelete = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            if(freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }

            keyValueFreq.erase(keyToDelete);

            keyIter.erase(keyToDelete);
        }

        // insert new key
        minFreq = 1;

        keyValueFreq[key] = {value, 1};

        freqList[1].push_front(key);

        keyIter[key] = freqList[1].begin();
    }
};