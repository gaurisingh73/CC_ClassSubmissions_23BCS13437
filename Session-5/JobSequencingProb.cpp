class MinHeap {
    constructor() {
        this.heap = [];
    }

    push(val) {
        this.heap.push(val);
        this.heapifyUp();
    }

    pop() {
        if (this.heap.length === 1) return this.heap.pop();
        let top = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.heapifyDown();
        return top;
    }

    top() {
        return this.heap[0];
    }

    size() {
        return this.heap.length;
    }

    heapifyUp() {
        let idx = this.heap.length - 1;
        while (idx > 0) {
            let parent = Math.floor((idx - 1) / 2);
            if (this.heap[parent] <= this.heap[idx]) break;
            [this.heap[parent], this.heap[idx]] =
            [this.heap[idx], this.heap[parent]];
            idx = parent;
        }
    }

    heapifyDown() {
        let idx = 0;
        while (2 * idx + 1 < this.heap.length) {
            let left = 2 * idx + 1, right = 2 * idx + 2;
            let smallest = left;
            if (right < this.heap.length && this.heap[right] 
            < this.heap[left]) smallest = right;
            if (this.heap[idx] <= this.heap[smallest]) break;
            [this.heap[idx], this.heap[smallest]] =
            [this.heap[smallest], this.heap[idx]];
            idx = smallest;
        }
    }
}

function jobSequencing(deadline, profit) {
    let n = deadline.length;
    let ans = [0, 0];
    let jobs = [];
    for (let i = 0; i < n; i++) {
        jobs.push([deadline[i], profit[i]]);
    }

    // sort the jobs based on deadline
    // in ascending order
    jobs.sort((a, b) => a[0] - b[0]);
    let pq = new MinHeap();

    for (let job of jobs) {
        
        // if job can be scheduled within its deadline
        if (job[0] > pq.size()) {
            pq.push(job[1]);
        }
        
        // Replace the job with the lowest profit
        else if (pq.size() > 0 && pq.top() < job[1]) {
            pq.pop();
            pq.push(job[1]);
        }
    }

    while (pq.size() > 0) {
        ans[1] += pq.pop();
        ans[0]++;
    }

    return ans;
}

// Driver Code 
let deadline = [2, 1, 2, 1, 1];
let profit = [100, 19, 27, 25, 15];
let ans = jobSequencing(deadline, profit);
console.log(ans[0] + " " + ans[1]);
