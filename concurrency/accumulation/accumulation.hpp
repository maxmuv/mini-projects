#include <thread>
#include <numeric>
#include <vector>

template <class Iterator, typename T>
void accumulate_block(Iterator first, Iterator last, T& result){
    result = std::accumulate(first, last, result);
};

template <class Iterator, typename T>
void parallel_accumulate(Iterator first, Iterator last, T& result){
    unsigned int size = std::distance(first, last);
    if (size == 0)
        return;
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads-1);
    unsigned int block_size = (size + num_threads -1) / num_threads;
    Iterator start_it = first;
    for (int i = 0; i < (num_threads - 1); ++i){
        Iterator end_it = start_it;
        std::advance(end_it, block_size);
        threads[i] = std::thread(accumulate_block<Iterator, T>, start_it, end_it, std::ref(results[i]));
        start_it = end_it;
    }
    accumulate_block<Iterator, T>( start_it, last, std::ref(results[num_threads-1]));
    for (auto & entry: threads)
        entry.join();
    result = std::accumulate(results.begin(), results.end(), result);
}
