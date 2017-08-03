#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>
#include <ANN/ANN.h>
#include <itkPoint.h>
using namespace std;
#include "vtkPolygon.h"
#include "vtkImplicitPolyData.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkTriangle.h"
#include "vtkFieldData.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"
#include <vtkVersion.h>
#include <vtkCellArray.h>
#include "vtkCellData.h"
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
#include <vtkDistancePolyDataFilter.h>
#include <vtkDoubleArray.h>

int main ( int, char *[] )
{
  //定义图像像素点对象
  typedef itk::Point<float,3>                               PointType;  
  PointType pnt;
 
    //读取VTK图像
    vtkSmartPointer<vtkPolyDataReader > vtkreader1=
    vtkSmartPointer<vtkPolyDataReader >::New();    //读金标准
    vtkSmartPointer<vtkPolyDataReader > vtkreader2=
    vtkSmartPointer<vtkPolyDataReader >::New();    //读程序分割
    //写VTK图像
    vtkSmartPointer<vtkPolyDataWriter> writer =  
    vtkSmartPointer<vtkPolyDataWriter>::New();

	vtkreader1->SetFileName("glodstandSPHARM_ellalign.vtk");
	vtkreader1->Update();
        vtkPolyData *glodcube = vtkreader1->GetOutput();
 
	vtkreader2->SetFileName("segautoSPHARM_ellalign.vtk");
	vtkreader2->Update();
        vtkPolyData *autocube = vtkreader2->GetOutput();
  
    vtkSmartPointer<vtkDistancePolyDataFilter> distanceFilter =
    vtkSmartPointer<vtkDistancePolyDataFilter>::New();

	vtkSmartPointer<vtkDistancePolyDataFilter> Normal_distances = vtkSmartPointer<vtkDistancePolyDataFilter>::New(); 
	Normal_distances->SetInput(testSample ); 
	Normal_distances->SetInput(1,bestModelReconstruction); 
	Normal_distances->SignedDistanceOff(); 
	Normal_distances->Update(); 

	 vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New(); 
	mapper->SetInputConnection( distanceFilter->GetOutputPort() ); 
	mapper->SetScalarRange( distanceFilter->GetOutput()->GetPointData()->GetScalars()->GetRange()[0], distanceFilter->GetOutput()->GetPointData()->GetScalars()->GetRange()[1]); 

 // vtkImplicitPolyData *polyToImplicitDataB = vtkImplicitPolyData::New();
  //imp->SetInput( autocube );

  return EXIT_SUCCESS;
}


