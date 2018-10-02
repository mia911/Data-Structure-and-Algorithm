D[x] = +oo; // toàn bộ mảng = +oo
D[start] = 0;
visited[x] = false; // toàn bộ mảng = false

//n la so dinh, m la so canh
//heap ho tro: them 1 phan tu, get phan tu lon hoac nho nhat, remove phan tu lon nhat/nho nhat
//them phan tu: o(log(heap.size()))
//get phan tu lon/nho nhat: O(1)
//remove: O(log(heap.size()))

heap.insert(start)

while (true) {
	x = heap.get();
	heap.remove();

    visited[x] = true; // đánh dấu đã tìm đc đường đi ngắn nhất tới x, D[x] là độ dài đường đi ngắn nhất từ start tới x
    for(y : (x, y) là 1 cạnh của đồ thị) {
        c = trọng số cạnh (x, y);
        if (D[y] > D[x] + c) { // tìm được đường đi ngắn hơn từ start tới y bằng cách đi qua x rồi mới đến y
            D[y] = D[x] + c;
            heap.insert(y);
        }
    }
}