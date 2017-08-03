#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

#include <vtkVersion.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPolyDataWriter.h>
#include <vtkPolyData.h>
#include <vtkPolyDataNormals.h>
#include <vtkPolyDataReader.h>
#include <vtkSmartPointer.h>
#include <vtkFloatArray.h>
#include <vtkPointData.h>
#include <vtkStructuredPointsReader.h>
#include <vtkStructuredPoints.h> 
int main ( int, char *[] )
{

	 vtkSmartPointer<vtkPolyDataReader > vtkreader=vtkSmartPointer<vtkPolyDataReader >::New();

	vtkreader->SetFileName("brain-3SPHARM_ellalign.vtk");

	vtkreader->Update();

static float x[8]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8};

//	vtkPolyDataNormals *cube=vtkPolyDataNormals::New();//创建数据集对象的实例
	vtkPolyData *cube = vtkreader->GetOutput();
	//cube->SetInputConnection(vtkreader->GetOutputPort());//为数据集添加点，定义其几何
	int npoint = 0 ;
	npoint= cube->GetNumberOfPoints();
	printf("%d\n",npoint);

	vtkFloatArray *scalars=vtkFloatArray::New();

	 scalars->SetNumberOfValues(37741);


	//读取ASD数据
	ifstream fin("asdtext6.txt");  
	double s;  
	int i=0;
	    while( fin >> s ) 
	    {    
		scalars->SetValue(i++,s);
	    }
	cout<<"i的值："<<i<<endl;

//	int i=0;
//	for(i=0;i<4002;i++){


 //		scalars->SetValue(i,x[i%8]);

//	}
	
	cube->GetPointData()->SetScalars(scalars);


  // Write the file
  vtkSmartPointer<vtkPolyDataWriter> writer =  
    vtkSmartPointer<vtkPolyDataWriter>::New();
  writer->SetFileName("test-asdtext6.vtk");
#if VTK_MAJOR_VERSION <= 5
  writer->SetInput(cube);
#else
  writer->SetInputData(cube);
#endif
  writer->Write();
  // Optional - set the mode. The default is binary.
  //writer->SetDataModeToBinary();
  //writer->SetDataModeToAscii();
 
 
 
  return EXIT_SUCCESS;
}
