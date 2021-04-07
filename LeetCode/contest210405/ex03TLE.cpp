/*
 * @Description: ex03  O（n^2） TLE
 * @Author: Marcel
 * @Date: 2021-04-05 16:34:18
 */

#include <iostream>
#include <vector>
#include <string>
#include<numeric>
#include<algorithm>

using namespace std;

int findmin(vector<int> &nums,int index){
    int res=0;
    int remove=-1;
    for(int i=0;i<=index;i++){
        if(nums[i]<res){
            res=nums[i];
            remove=i;
        }
    }
    nums[remove]=0;
    return res;
}

int magicTower(vector<int>& nums) {
    long sum=accumulate(nums.begin(),nums.end(),(long)1);
    if(sum<=0)return -1;
    
    int res=0;

    sum=1;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum<=0){
            sum-=findmin(nums,i);
            res++;
        }
    }

    return res;

}

vector<int>vec={86711,55316,67434,-58220,-48924,6016,-95158,-63952,-42473,-62718,56281,19870,-38971,-13728,99922,-63556,-28337,7347,73132,-59162,-67381,72768,83893,10524,-42746,70695,97648,89215,-69800,-34173,-86726,85070,56901,55087,38322,97803,97500,-98589,-97942,-92412,-11563,86640,-30575,-4528,20902,47200,-84610,-69943,48810,-48384,-66350,-51741,61345,38555,66057,69580,14520,14966,68984,-60720,85070,-75278,-31945,-49882,-88517,-541,67919,-4031,23232,22077,64342,-39354,-65465,-46485,-81548,-94062,64292,-81077,-7914,-9052,22821,21423,-1317,-47634,94346,-56679,-84923,88315,-96893,-23223,27351,76353,80053,-25008,-78247,43988,-60425,24977,-95157,32101,-69130,24788,89527,-24631,-88848,-3664,19008,59173,60323,-11735,12834,-20654,-87794,-80049,67526,55217,-62346,-46855,-31272,16604,-33770,-20793,-25657,-17463,38887,-47785,-17758,96187,1860,-29039,31750,-3053,-20115,19208,-56937,-95842,-92119,3216,31808,-43193,-55431,-75052,70027,-87820,-74532,-20831,37305,62600,34584,78224,79282,3963,-85318,-23809,87206,-68011,88984,-71680,-2828,-84997,27633,91666,-8892,39838,-76945,-14457,62810,10403,-13116,49408,-1322,-37745,30242,-82683,52166,-59898,-21690,33275,-18934,99475,33435,-67561,93363,55716,-5733,-81572,-55760,-9696,-35380,70242,98588,-78998,35472,-42032,29005,63528,-97982,23853,-8829,9479,-75481,-30818,-52874,-13305,-73807,29942,25430,65448,59988,-13641,-69914,-46875,95699,-79910,71335,-71709,47179,21571,-85776,53905,-8070,57626,71301,-90698,-78715,-59299,61581,-15957,95039,19503,-35072,43878,-62402,11542,48989,89140,-2170,-87717,-43545,71197,24468,-55544,-27793,4728,-97843,-56446,-80133,-9700,30598,-30235,-3435,-55061,-75821,76892,32389,-14351,-26349,7300,-68760,-74198,-26532,-89202,-74083,-13164,-35201,95104,16274,28799,91759,-46075,66990,-10870,-30709,7783,-64122,-55386,71295,-92255,73743,18722,-59168,99476,89429,15211,-11011,-5328,-74334,-32023,-62828,44588,-10184,35946,79475,51283,-92823,-93230,-75945,-82581,4591,-600,-62213,-85526,-28777,-83042,93672,28820,-68719,-55849,9330,-87904,6253,83357,30321,1050,-38396,-33720,-35706,92749,14836,13528,58447,74981,-75964,-15803,34547,-79040,-29847,-58521,-91227,-47969,98317,-59345,-5191,89022,-77260,27735,-45974,-35744,63788,-72660,-93299,34513,-80274,-88751,-38469,-22438,-47857,-31681,-62578,92651,-94403,-54008,13775,-15605,21704,-37366,-62074,-74925,53795,-24372,-46141,2759,-48720,64030,-77859,-17317,-4286,58659,811,-11701,-27231,-17963,-19688,-97113,79242,8028,-12363,8689,89552,65487,38306,-25881,32557,-25872,-85403,78865,-69636,59211,17459,46018,-58564,94915,12378,26017,-18770,9318,-68040,-1618,17683,39077,7236,48165,-21446,-92084,74574,-58422,-31106,-47634,34675,-89048,-43945,83475,70535,-69444,83948,-63559,47028,39210,49812,-25954,-77754,-78540,-63986,92111,70411,-78361,9569,28250,-60587,-66890,47901,72882,93486,-39172,28738,-48462,85321,26250,6115,-12900,66910,42149,-97618,66002,83148,-260,10618,-35564,39479,94493,-32979,96628,-45947,-28426,-52844,-35191,-51239,60683,49734,47985,47152,-77222,-44627,15178,-97850,17331,-19432,-1589,29977,27103,12504,-43729,-32643,-21597,-3712,85744,19132,87059,-75375,-81123,91725,-46181,-2504,42248,-80772,585,82929,-35244,50296,-35405,-74349,8006,-26689,-71105,-27353,68543,92879,-75271,29759,-49432,-69310,-98077,26559,52231,4778,-19229,-15627,-3391,-15514,41066,5432,-22948,62076,-52865,65438,89635,46358,52978,54139,84312,-27953,715,12908,-52222,-30821,-28104,-30591,-5378,-61961,-64440,-66524,83458,48315,-71855,-58265,-73797,40587,-52469,-88745,20251,71968,-33146,-28638,-13787,32738,55223,-18125,63164,31223,65319,-40040,75072,75380,-85350,98256,-7532,30411,79745,-56204,16103,-54620,-45852,-48773,68394,-51449,-15272,-22298,44346,85668,56589,-24105,93937,-8861,93041,46783,42324,87588,-42048,-25301,-72236,33398,82930,31535,47285,-88989,-43282,-65674,-14858,8948,-1873,25936,-68492,-28777,-76856,-7658,44394,-50834,83155,-24410,15902,90945,-78480,75676,-38401,71781,-31601,-97017,-34941,44632,98045,-32314,-54184,77940,90357,56991,5322,-8617,83390,-53370,58245,-28990,-26416,92085,-55767,20549,-96556,-20751,11406,-13141,-51622,33302,-8671,-90386,-4006,-42222,36249,-3244,89859,26061,-50038,33164,-22266,-14965,71517,1133,66876,-80127,35450,16513,-22348,26824,64431,2143,703,38771,-40751,-54856,62916,80311,74964,40735,-91102,68821,-88531,82578,70832,-78050,-69357,-1270,57064,-94867,932,58133,-338,-39498,52771,-2210,72097,-2195,-50408,13740,-73104,-39824,17065,8016,-71061,72262,-15825,-71792,-5227,-98533,-41677,-734,-43714,25383,89403,26177,-50917,-56493,2241,39347,97479,1119,-94001,27743,44296,24417,66930,-55045,-28598,-5364,-11639,-69946,52838,-2041,-36553,-36868,-25071,16381,1234,-39399,89605,-88711,62419,29602,-23964,97892,15323,-60753,62291,-82343,-98301,-39487,34593,-2330,84357,36325,43260,-24764,96102,-79400,8038,96005,-78946,71018,-63622,33005,-19458,84320,81834,-75086,21036,-27786,81295,64656,-14332,-66259,-36819,90937,98908,-80117,-30188,-69513,-37490,-23301,-50580,-28190,14163,-89765,-37681,27857,-98210,-8701,87119,47513,2707,48821,96930,80025,-84959,-81550,-93032,-6384,-67021,98785,-85690,63651,79522,-30146,-52114,60412,-49394,-83463,-4968,27295,-34362,50046,69030,-48664,-69027,32257,-72292,55121,25428,10236,89322,317,-79896,-37587,24123,35930,-23096,-36142,-7166,58869,11857,-55762,33823,53683,3235,-6973,96749,88432,-61296,-79708,35547,-13351,49300,72967,-28257,39919,-64105,-57212,-15025,82319,-54009,54967,8443,58872,8125,45988,-63175,10587,-60515,64329,27474,-58447,30122,41261,37572,71749,-36179,35766,83578,76106,-18630,-34525,-92566,71621,4577,-16113,-80713,-7847,52653,-30521,92576,-33416,-5350,33389,29121,-33856,-40930,91197,-29651,-97351,65145,-88448,73441,-90639,29474,74813,-48490,-697,-31332,96591,58945,65498,-63799,-56712,27431,45516,34663,87847,91602,-99117,25258,63473,-37141,76656,-60432,48634,51670,-2979,23692,-40151,-38527,-74957,51136,54059,14369,-77643,-10481,65428,-93226,-6458,94812,29510,30910,50228,46088,145,61921,96780,-91833,36578,-33224,75338,-96908,-78287,-59344,-45532,85420,82898,-51354,-26503,-65066,72330,-84367,24506,45394,44755,63725,47940,29782,98457,-65756,88965,79309,87685,-8489,25588,93424,-54113,-51500,95708,-54807,50378,-50035,-4271,9768,95269,68568,-13356,-22673,76236,10191,-71333,27046,88948,-49094,-20932,-9749};

int main(void){
    cout<<magicTower(vec);
    
}
