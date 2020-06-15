#include <fstream>
#include <vector>
using namespace std;

long long findApartmetsCount(long long n, long long k, long long x, long long y) {
	long long apartmetsCount = 0;
	long long floor = 1;
	long long multiplicityFloor = 1;

	while (floor <= n) {
		floor += 1;
		if (multiplicityFloor < k) {
			apartmetsCount += y;
			multiplicityFloor += 1;
		}
		else {
			apartmetsCount += x;
			multiplicityFloor = 1;
		}
	}

	return apartmetsCount;
}

long long findRoomsToMultipleFloors(long long k, long long x, long long y) {
	long long roomsToMultipleFloors = 0;
	long long multiplicityFloor = 1;

	while (multiplicityFloor < k) {
		roomsToMultipleFloors += y;
		multiplicityFloor++;
	}

	return roomsToMultipleFloors += x;
}

long long calcFloor(long long vectRoom, long long apartmetsCount, long long roomsToMultipleFloors, long long n, long long k, long long y) {
	vectRoom = vectRoom % apartmetsCount;
	if (vectRoom == 0)
		return n;
	else {
		long long residue = vectRoom % roomsToMultipleFloors;

		long long floor = (vectRoom / roomsToMultipleFloors) * k;
		if ((residue % y) == 0) {
			floor += residue / y;
		}
		else {
			floor += residue / y + 1;
		}

		return floor;
	}
}

int main()
{

	ifstream input;
	input.open("input.txt");
	long long n;
	input >> n;
	long long k;
	input >> k;
	long long x, y;
	input >> x >> y;
	long long apartmetsCount = findApartmetsCount(n, k, x, y);
	long long roomsToMultipleFloors = findRoomsToMultipleFloors(k, x, y);

	short int q;
	input >> q;

	vector<long long> vectRooms(q);
	for (short int i = 0; i < q; i++)	// Для того, чтобы не обращаться к файлу много раз
		input >> vectRooms[i];
	input.close();
	ofstream output;
	output.open("output.txt");
	for (short int i = 0; i < q; i++)
	{
		output << calcFloor(vectRooms[i], apartmetsCount, roomsToMultipleFloors, n, k, y) << endl;
	}

	return 0;
}