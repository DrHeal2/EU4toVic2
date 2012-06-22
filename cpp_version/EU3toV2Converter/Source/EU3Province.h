#ifndef EU3PROVINCE_H_
#define EU3PROVINCE_H_


#include "Date.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

class Object;
class EU3Country;



struct EU3PopRatio {
	string culture;
	string religion;
	double popRatio;
};


class EU3Province {
	public:
		EU3Province(Object* obj);

		void						addCore(string tag);
		void						removeCore(string tag);
		bool						wasColonised();
		bool						wasPaganConquest(string ownerReligion);
		bool						hasBuilding(string building);

		int						getNum() { return num; };
		string					getOwner() { return owner; };
		vector<EU3Country*>	getCores(map<string, EU3Country*> countries);
		int						getPopulation() { return population; };
		bool						isColony() { return colony; };
		bool						isCOT() { return centerOfTrade; };
		date						getLastPossessedDate(string tag);
		vector<EU3PopRatio>	getPopRatios() { return popRatios; };

		void						setOwner(string newOwner) { owner = newOwner; };
		void						setCOT(bool isCOT) { centerOfTrade = isCOT; };

	private:
		void	checkBuilding(Object* provinceObj, string building);
		void	buildPopRatios();
		void	decayPopRatios(date olddate, date newdate, EU3PopRatio& currentPop);

		int									num;
		string								owner;
		//controller
		vector<string>						cores;
		int									population;
		bool									colony;
		bool									centerOfTrade;
		vector< pair<date, string> >	ownershipHistory;
		map<string, date>					lastPossessedDate;
		vector< pair<date, string> >	religionHistory;
		vector< pair<date, string> >	cultureHistory;
		vector<EU3PopRatio>				popRatios;
		map<string, bool>					buildings;
};


#endif // EU3PROVINCE_H_