#include <iostream>
#include <vector>
#include "Vector3.h"
using namespace std;
class Target
{
public:
	Vector3	targetNormal; // normal of the target
	Vector3 location; //center of the target
	double radius; //radius of the target

};

// the derivation is taken from https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
bool intersection_of_plane_with_shooterdirection(const Vector3 &normal, const Vector3 &p0, const Vector3 &l0, const Vector3 &l, float &t)
{
	//compute the dot product between the normal of the target and the direction of the shooter. 
	//If the denomiator is too small, then there are infinte solution that the direction of shooter
	//and the normal direction of the target exactly coincide or they do not coincide at all 
	double denominator = dot(normal, l);
	if (denominator > 1e-6) {
		Vector3 p0l0 =p0 - l0;
		t = dot(p0l0, normal) / denominator;
		return (t >= 0);
	}
	return false;
}

bool isTargetHit(const Vector3 &targetnormal, const Vector3 &targetposition, const double &targetradius, const Vector3 &shooterposition, const Vector3 &shooterdirection)
{
	float t = 0;
	//check whether the direction of the shooter is towards the plane where the target may be present.
	if (intersection_of_plane_with_shooterdirection(targetnormal, targetposition, shooterposition, shooterdirection, t))
	{
		//Since ray intersects the plane,compute the intersection point
		Vector3 p = shooterposition + shooterdirection * t;
		// compute the distance of the intersection point from the target location(i.e., center of the target)
		Vector3 v = p - targetposition;
		//computing the dot product of v with itself. This is same as the square of the distance.
		float d2 = dot(v, v);
		// Take the square root of d2 to find the distance
		float dist = sqrtf(d2);
		//check the distance with target radius. If the distance is less than the radius of the target, the shooter hits the target
		if (dist<= targetradius)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}

	return false;
}
void main()
{
	Target t[3];
	t[0].location = (1, 2, 1);
	t[1].location = (-3, -4, -3);
	t[2].location = (-4, -9, -7);

	t[0].radius = 0.002;
	t[1].radius = 1.0;
	t[2].radius = 4.0;

	t[0].targetNormal = (1, 2, 4);
	t[1].targetNormal = (3, 2, 3);
	t[2].targetNormal = (1, 3, 3);

	Vector3 shooterposition(0, 0, 0);
	Vector3 shooterdirection(3,3,3);

	cout << "1st Target hit:" << isTargetHit(t[0].targetNormal, t[0].location, t[0].radius, shooterposition, shooterdirection)<<endl;
	cout << "2nd Target hit:" << isTargetHit(t[1].targetNormal, t[1].location, t[1].radius, shooterposition, shooterdirection)<<endl;
	cout << "3rd Target hit:" << isTargetHit(t[2].targetNormal, t[2].location, t[2].radius, shooterposition, shooterdirection)<<endl;
	return;
}