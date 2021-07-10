/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

using T = double; // or long long
const T EPS = 1e-9; // might want to change
using P = pair<T,T>; using vP = vec<P>; using Line = pair<P,P>;
int sgn(T a) { return (a>EPS)-(a<-EPS); }
T sq(T a) { return a*a; }

bool close(const P& a, const P& b) { 
	return sgn(a.fr-b.fr) == 0 && sgn(a.sc-b.sc) == 0; } 
T norm(const P& p) { return sq(p.fr)+sq(p.sc); }
T abs(const P& p) { return sqrt(norm(p)); }
T arg(const P& p) { return atan2(p.sc,p.fr); }
P conj(const P& p) { return P(p.fr,-p.sc); }
P perp(const P& p) { return P(-p.sc,p.fr); }
P dir(T ang) { return P(cos(ang),sin(ang)); }

P operator-(const P& l) { return P(-l.fr,-l.sc); }
P operator+(const P& l, const P& r) { 
	return P(l.fr+r.fr,l.sc+r.sc); }
P operator-(const P& l, const P& r) { 
	return P(l.fr-r.fr,l.sc-r.sc); }
P operator*(const P& l, const T& r) { 
	return P(l.fr*r,l.sc*r); }
P operator*(const T& l, const P& r) { return r*l; }
P operator/(const P& l, const T& r) { 
	return P(l.fr/r,l.sc/r); }
P operator*(const P& l, const P& r) { 
	return P(l.fr*r.fr-l.sc*r.sc,l.sc*r.fr+l.fr*r.sc); }
P operator/(const P& l, const P& r) { 
	return l*conj(r)/norm(r); }
P& operator+=(P& l, const P& r) { return l = l+r; }
P& operator-=(P& l, const P& r) { return l = l-r; }
P& operator*=(P& l, const T& r) { return l = l*r; }
P& operator/=(P& l, const T& r) { return l = l/r; }
P& operator*=(P& l, const P& r) { return l = l*r; }
P& operator/=(P& l, const P& r) { return l = l/r; }

P unit(const P& p) { return p/abs(p); }
T dot(const P& a, const P& b) { return a.fr*b.fr+a.sc*b.sc; }
T cross(const P& a, const P& b) { return a.fr*b.sc-a.sc*b.fr; }
T cross(const P& p, const P& a, const P& b) {
	return cross(a-p,b-p); }
P reflect(const P& p, const Line& l) { 
	P a = l.fr, d = l.sc-l.fr;
	return a+conj((p-a)/d)*d; }
P foot(const P& p, const Line& l) { 
	return (p+reflect(p,l))/(T)2; }
bool p_on_seg(const P& p, const Line& l) {
	return sgn(cross(l.fr,l.sc,p)) == 0 && sgn(dot(p-l.fr,p-l.sc)) <= 0; }