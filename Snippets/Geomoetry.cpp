typedef complex<long double> p;
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(p(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))


bool intersect(p &a, p &b, p &p, p &q,p &ret) {
    //handle degenerate cases 
	// (2 parallel lines, 2 identical lines, line is 1 p)
    ld d1 = cross(p - a, b - a);
    ld d2 = cross(q - a, b - a);
    ret = (d1 * q - d2 * p) / (d1 - d2);
    if(fabs(d1 - d2) > EPS) return 1;
    return 0;
}

bool pOnLine(const p& a, const p& b, const p& p) {
    // degenerate case: line is a p
    return fabs(cross(vec(a,b),vec(a,p))) < EPS;
}

bool pOnRay(const p& a, const p& b, const p& p) {
    //IMP NOTE: a,b,p must be collinear
    return dot(vec(a,p), vec(a,b)) > -EPS;
}

bool pOnSegment(const p& a, const p& b, const p& p) {
    if(!colliner(a,b,p)) return 0;
    return pOnRay(a, b, p) && pOnRay(b, a, p);
}

long double pLineDist(const p& a, const p& b, const p& p) {
	// handle degenrate case: (a,b) is p
	return fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)));
}

long double pSegmentDist(const p& a, const p& b, const p& p) {
	if (dot(vec(a,b),vec(a,p)) < EPS)
		return length(vec(a,p));
	if (dot(vec(b,a),vec(b,p)) < EPS)
		return length(vec(b,p));
	return pLineDist(a, b, p);
}

int count(p p1, p p2) {
	return 
	abs(gcd(p1.x-p2.x,p1.y-p2.y))+1;
}

//====================================================

//count interior
int picksTheorm(int a, int b) {
	return a - b / 2 + 1;
}

//get angle opposite to side a
long double cosRule(long double a, long double b, long double c) {
        // Handle denom = 0
	long double res = (b * b + c * c - a * a) / (2 * b * c);
	if ( fabs(res-1)<EPS)
                res = 1;
        if ( fabs(res+1)<EPS)
                res = -1;
	return acos(res);
}

long double sinRuleAngle(long double s1, long double s2, long double a1) {
        // Handle denom = 0
	long double res = s2 * sin(a1) / s1;
	if ( fabs(res-1)<EPS)
                res = 1;
        if ( fabs(res+1)<EPS)
                res = -1;
	return asin(res);
}

long double sinRuleSide(long double s1, long double a1, long double a2) {
        // Handle denom = 0
	long double res = s1 * sin(a2) / sin(a1);
	return fabs(res);
}
//================================================

/*
 *        u
 *       /|\
 *      / | \
 *    a/  |  \b
 *    /   |m  \
 *   /____|____\
 *  p  h   c-h  q
 */

int dcmp(const double &a, const double &b) {
	if (fabs(a - b) < EPS)
		return 0;
	return ((a > b) << 1) - 1;
}

int triangleThirdp(const p &p, const p &q, const double &a,
		const double &b, p &u1, p &u2) {
	p pq = vec(p, q);
	double c = length(pq);
	double arr[] = { a, b, c };
	sort(arr, arr + 3);
	if (dcmp(arr[0] + arr[1], arr[2]) < 0)
		return false;

	//m^2=a^2-h^2
	//m^2=b^2-(c-h)^2
	//m^2=b^2-(c^2-2ch+h^2)
	//m^2=b^2-c^2+2ch-h^2
	//a^2-h^2=b^2-c^2+2ch-h^2
	//0=b^2-c^2+2ch-h^2-a^2+h^2
	//0=b^2-c^2+2ch-a^2
	//2ch=a^2-b^2+c^2
	//h=(a^2-b^2+c^2)/2c
	double h = (a * a - b * b + c * c) / (2.0 * c);
	double sq=a * a - h * h;
	if(!dcmp(sq,0))sq=0;
	double m = sqrt(sq);
	p npq = normalize(pq);
	p prp = perp(npq);
	u1 = p + (npq * h) + m * prp;
	u2 = p + (npq * h) - m * prp;
	return 1 + (dcmp(arr[0] + arr[1], arr[2]) != 0);
}

//=====================================
void circle2(const p& p1, const p& p2, p& cen, long double& r) {
	cen = mid(p1,p2);
	r = length(vec(p1,p2)) / 2;
}

bool circle3(const p& p1, const p& p2, const p& p3, p& cen,
		long double& r) {
	p m1 = mid(p1,p2);
	p m2 = mid(p2,p3);
	p perp1 = perp(vec(p1,p2));
	p perp2 = perp(vec(p2,p3));
	bool res = intersect(m1, m1 + perp1, m2, m2 + perp2, cen);
	r = length(vec(cen,p1));
	return res;
}

STATE circlep(const p & cen, const long double & r, const p& p) {
	long double lensqr = lengthSqr(vec(cen,p));
	if (fabs(lensqr - r * r) < EPS)
		return BOUNDRY;
	if (lensqr < r * r)
		return IN;
	return OUT;
}