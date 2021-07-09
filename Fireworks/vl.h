#pragma once
/*
Header file with templates for vector functions
*/
#define M_PI 3.14159265358979323846


namespace vl
{
	template <class VectorClass> static float Heading(VectorClass a)
	{
		return atan(a.y / a.x) * 180 / M_PI;
	}
	template <class VectorClass> static VectorClass VectorAdd(VectorClass a, VectorClass b)
	{
		return VectorClass(a.x + b.x, a.y + b.y);
	}

	template <class VectorClass> static void VectorAddToA(VectorClass& a, VectorClass b)
	{
		a.x += b.x;
		a.y += b.y;
	}

	template <class VectorClass> static VectorClass VectorSub(VectorClass a, VectorClass b)
	{
		return VectorClass(a.x - b.x, a.y - b.y);
	}
	template <class VectorClass> static VectorClass VectorSubFloat(VectorClass a, float b)
	{
		return VectorClass(a.x - b, a.y - b);
	}
	template <class VectorClass> static void VectorSubFromA(VectorClass& a, VectorClass b)
	{
		a.x -= b.x;
		a.y -= b.y;
	}


	template <class VectorClass> static void VectorMulA(VectorClass& a, float scale)
	{
		a.x *= scale;
		a.y *= scale;
	}
	template <class VectorClass> static VectorClass VectorMul(VectorClass a, float scale)
	{
		return VectorClass(a.x * scale, a.y * scale);
	}
	template <class VectorClass> static VectorClass VectorDiv(VectorClass a, float scale)
	{
		return VectorClass(a.x / scale, a.y / scale);
	}
	template <class VectorClass> static void VectorDivA(VectorClass& a, float scale)
	{
		a.x /= scale;
		a.y /= scale;
	}
	template <class VectorClass> static void PrintVector(VectorClass a)
	{
		std::cout << "(" << a.x << ", " << a.y << ")" << std::endl;
	}


	template <class VectorClass> static float Magnitude(VectorClass a)
	{
		return sqrt(a.x * a.x + a.y * a.y);
	}
	template <class VectorClass> static void SetMagnitude(VectorClass& a, float new_mag)
	{
		float mag = vl::Magnitude(a);
		if (mag != 0)
		{
			a = vl::VectorDiv(a, mag);
			a = vl::VectorMul(a, new_mag);
		}
	}

	template <class VectorClass> static void SetMagnitudeRelative(VectorClass& a, VectorClass b, float new_mag)
	{
		vl::VectorSubFromA(a, b);

		float mag = vl::Magnitude(a);
		if (mag != 0)
		{
			a = vl::VectorDiv(a, mag);
			a = vl::VectorMul(a, new_mag);
		}
		vl::VectorAddToA(a, b);


	}

	static sf::Vector2f random2D()
	{
		sf::Vector2f pos;
		pos.x = static_cast<float>(rand() % 200 - 100);
		pos.y = static_cast<float>(rand() % 200 - 100);

		vl::SetMagnitude(pos, 1.f);
		return pos;
	}

	template <class VectorClass> static float MagSq(VectorClass a)
	{
		return a.x * a.x + a.y * a.y;
	}

	template <class VectorClass> static void Limit(VectorClass& a, float max_mag)
	{
		float mSq = MagSq(a);
		if (mSq > max_mag * max_mag)
		{
			VectorDivA(a, sqrt(mSq));
			VectorMulA(a, max_mag);
			//PrintVector(a);
		}

	}
	/*static float map(float value, float start1, float start2, float stop1, float stop2)
	{
		return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
	}*/

}

