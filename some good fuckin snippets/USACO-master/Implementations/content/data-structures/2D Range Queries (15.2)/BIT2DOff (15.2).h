/**
 * Description: point update and rectangle sum with offline 2D BIT. 
	* For each of the points to be updated, $x\in (0,SZ)$ and $y\neq 0$.
 * Time: O(N\log^2 N)
 * Memory: O(N\log N)
 * Source: Own
 * Verification: 
 	* https://dmoj.ca/problem/occ19g4
 	* http://www.usaco.org/index.php?page=viewproblem2&cpid=722 (753 ms)
 	* http://www.usaco.org/index.php?page=viewproblem2&cpid=601 (679 ms)
 */

template<class T = int, int SZ = maxn> struct OffBIT2D { 
	bool mode = 0; // mode = 1 -> initialized
	vec<pii> todo; // locations of updates to process
	int cnt[SZ], st[SZ];
	vi val; vector<T> bit; // store all BITs in single vector
	void init() { assert(!mode); mode = 1;
		int lst[SZ]; for(int i = 0; i < SZ; ++i) lst[i] = cnt[i] = 0;
		sort(all(todo),[](const pii& a, const pii& b) { 
			return a.sc < b.sc; });
		for(auto t : todo) for (int x = t.fr; x < SZ; x += x&-x) 
			if (lst[x] != t.sc) lst[x] = t.sc, cnt[x] ++;
		int sum = 0; for(int i = 0; i < SZ; ++i) lst[i] = 0, st[i] = (sum += cnt[i]);
		val.resize(sum); bit.resize(sum); reverse(all(todo));
		for(auto t : todo) for (int x = t.fr; x < SZ; x += x&-x) 
			if (lst[x] != t.sc) lst[x] = t.sc, val[--st[x]] = t.sc;
	}
	int rank(int y, int l, int r) {
		return upper_bound(begin(val)+l,begin(val)+r,y)-begin(val)-l; }
	void UPD(int x, int y, T t) {
		for (y = rank(y,st[x],st[x]+cnt[x]); y <= cnt[x]; y += y&-y) 
			bit[st[x]+y-1] += t; }
	void upd(int x, int y, T t) { 
		if (!mode) todo.pb({x,y});
		else for (;x<SZ;x+=x&-x) UPD(x,y,t); }
	int QUERY(int x, int y) { T res = 0;
		for (y = rank(y,st[x],st[x]+cnt[x]); y; y -= y&-y) res += bit[st[x]+y-1];
		return res; }
	T query(int x, int y) { assert(mode);
		T res = 0; for (;x;x-=x&-x) res += QUERY(x,y);
		return res; }
	T query(int xl, int xr, int yl, int yr) { 
		return query(xr,yr)-query(xl-1,yr)
			-query(xr,yl-1)+query(xl-1,yl-1); }
};