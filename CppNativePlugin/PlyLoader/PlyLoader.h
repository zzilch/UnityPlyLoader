#pragma once

#if defined _WIN32 || defined __CYGWIN__ || defined __MINGW32__
    #ifdef BUILDING_DLL
        #ifdef __GNUC__
            #define DLL_PUBLIC __attribute__ ((dllexport))
        #else
            #define DLL_PUBLIC __declspec(dllexport) 
        #endif
    #else
        #ifdef __GNUC__
            #define DLL_PUBLIC __attribute__ ((dllimport))
        #else
            #define DLL_PUBLIC __declspec(dllimport) 
        #endif
    #endif
    #define DLL_LOCAL
#else
    #if __GNUC__ >= 4
        #define DLL_PUBLIC __attribute__ ((visibility ("default")))
        #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
    #else
        #define DLL_PUBLIC
        #define DLL_LOCAL
    #endif
#endif

#include <vector>
#include <string>
#include "ml_mesh_type.h"

using namespace std;

class PlyFileObject
{
public:
	enum MeshElement {
		MM_NONE = 0x00000000,
		MM_VERTCOORD = 0x00000001,
		MM_VERTNORMAL = 0x00000002,
		MM_VERTFLAG = 0x00000004,
		MM_VERTCOLOR = 0x00000008,
		MM_VERTQUALITY = 0x00000010,
		MM_VERTMARK = 0x00000020,
		MM_VERTFACETOPO = 0x00000040,
		MM_VERTCURV = 0x00000080,
		MM_VERTCURVDIR = 0x00000100,
		MM_VERTRADIUS = 0x00000200,
		MM_VERTTEXCOORD = 0x00000400,
		MM_VERTNUMBER = 0x00000800,

		MM_FACEVERT = 0x00001000,
		MM_FACENORMAL = 0x00002000,
		MM_FACEFLAG = 0x00004000,
		MM_FACECOLOR = 0x00008000,
		MM_FACEQUALITY = 0x00010000,
		MM_FACEMARK = 0x00020000,
		MM_FACEFACETOPO = 0x00040000,
		MM_FACENUMBER = 0x00080000,
		MM_FACECURVDIR = 0x00100000,

		MM_WEDGTEXCOORD = 0x00200000,
		MM_WEDGNORMAL = 0x00400000,
		MM_WEDGCOLOR = 0x00800000,

		// 	Selection
		MM_VERTFLAGSELECT = 0x01000000,
		MM_FACEFLAGSELECT = 0x02000000,

		// Per Mesh Stuff....
		MM_CAMERA = 0x08000000,
		MM_TRANSFMATRIX = 0x10000000,
		MM_COLOR = 0x20000000,
		MM_POLYGONAL = 0x40000000,
		MM_UNKNOWN = 0x80000000,

		MM_ALL = 0xffffffff
	};

	PlyFileObject(const char* fileName);
	vector<float> verts;
	vector<float> norms;
	vector<unsigned char> colors;
	vector<unsigned int> faces;
	vector<float> uvCoords;
	string textureName;
	CMeshO cm;

private:
	void Enable(int openingFileMask);
	void updateDataMask(int openingFileMask);
};

extern "C" {
	DLL_PUBLIC PlyFileObject* LoadPly(const char* fileName);

	DLL_PUBLIC void UnLoadPly(PlyFileObject* plyFile);

	DLL_PUBLIC float* GetPlyVerts(PlyFileObject* plyFile, unsigned int& count);

	DLL_PUBLIC float* GetPlyNormals(PlyFileObject* plyFile, unsigned int& count);

	DLL_PUBLIC unsigned char* GetPlyColors(PlyFileObject* plyFile, unsigned int& count);

	DLL_PUBLIC unsigned int* GetPlyIndexs(PlyFileObject* plyFile, unsigned int& count);

	DLL_PUBLIC float* GetPlyUvs(PlyFileObject* plyFile, unsigned int& count);

	DLL_PUBLIC const char* GetPlyTextureName(PlyFileObject* plyFile);
};
