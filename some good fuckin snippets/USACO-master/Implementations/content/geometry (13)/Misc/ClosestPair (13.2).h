/**
 * Description: line sweep to find two closest points 
 * Time: O(N\log N)
 * Source: Own
 * Verification: https://open.kattis.com/problems/closestpair2
 */

#include "../Primitives/Point.h"

pair<P,P> solve(vP v) {
	pair<ld,pair<P,P>> bes; bes.f = INF;
	set<P> S; int ind = 0;
	sort(all(v));
	F0R(i,sz(v)) {
		if (i && v[i] == v[i-1]) return {v[i],v[i]};
		for (; v[i].f-v[ind].f >= bes.f; ++ind) 
			S.erase({v[ind].s,v[ind].f});
		for (auto it = S.ub({v[i].s-bes.f,INF});
			it != end(S) && it->f < v[i].s+bes.f; ++it) {
			P t = {it->s,it->f};
			ckmin(bes,{abs(t-v[i]),{t,v[i]}});
		}
		S.insert({v[i].s,v[i].f});
	}
	return bes.s;
}

pair<P,P> solve(vP v) {
	pair<int,pair<P,P>> bes; bes.fr = inf;
	set<P> S; int ind = 0;
	sort(all(v));
	for(int i = 0; i < sz(v); ++i) {
		if (i && v[i] == v[i-1]) return {v[i],v[i]};
		for (; v[i].fr-v[ind].fr >= bes.fr; ++ind) 
			S.erase({v[ind].sc,v[ind].fr});
		for (auto it = S.upper_bound({v[i].sc-bes.fr,inf});
			it != end(S) && it->fr < v[i].sc+bes.fr; ++it) {
			P t = {it->sc,it->fr};
		pair<int,pair<P,P>> wen = {abs(t-v[i]),mp(t,v[i])};
			amin(bes,wen);
		}
		S.insert({v[i].sc,v[i].fr});
	}
	return bes.sc;
}