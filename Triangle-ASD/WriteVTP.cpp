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
int numBorderPts = 4002;
int main ( int, char *[] )
{
  //定义图像像素点对象
  typedef itk::Point<float,3>                               PointType;  
  PointType pnt;
  ANNpointArray borderPts1 = annAllocPts( numBorderPts, 3 );  //程序分割三角化后的图像像素坐标
  ANNpointArray borderPts2 = annAllocPts( numBorderPts, 3 ); //金标准三角化后的图像像素坐标
    //读取VTK图像
    vtkSmartPointer<vtkPolyDataReader > vtkreader=
    vtkSmartPointer<vtkPolyDataReader >::New();
    //写VTK图像
    vtkSmartPointer<vtkPolyDataWriter> writer =  
    vtkSmartPointer<vtkPolyDataWriter>::New();

	vtkreader->SetFileName("glodstandSPHARM_ellalign.vtk");
	vtkreader->Update();
        vtkPolyData *cube = vtkreader->GetOutput();
        vtkFloatArray *scalars=vtkFloatArray::New();
        scalars->SetNumberOfValues(numBorderPts);

  
    double s; 
    int sum = 0; 
    int i = 0;
  //初始化ANNpointArray borderPts1
    ifstream fin("segauto.txt");  
    while( fin >> s ) 
    {    
	if(sum%3==0 && sum!=0){
		sum = 0;
		i++;
	} 
	pnt[sum] = s;
	borderPts1[i][sum] = pnt[sum];
	sum++;
    }
   ANNkd_tree *borderTree1 = new ANNkd_tree( borderPts1, numBorderPts, 3 );

    //初始化ANNpointArray borderPts2
    sum = 0;
    i = 0;
    ifstream fin1("glodstand.txt");  
    while( fin1 >> s ) 
    {    
	if(sum%3==0 && sum!=0){
		sum = 0;
		i++;
	} 
	pnt[sum] = s;
	borderPts2[i][sum] = pnt[sum];
	sum++;
    }
    ANNkd_tree *borderTree2 = new ANNkd_tree( borderPts2, numBorderPts, 3 );

//// calculate surface distance measures
  double avgDistance = 0;
  double avgSqrDistance = 0;
  double maxDistance = 0;
  ANNidxArray  nnIdx = new ANNidx[1];
  ANNdistArray dists = new ANNdist[1];

  for(unsigned int idx1=0; idx1<numBorderPts; idx1++) {
    borderTree2->annkSearch( borderPts1[idx1], 1, nnIdx, dists);
    avgSqrDistance += dists[0];
    double d = sqrt( dists[0] );
    avgDistance += d;
  //  cout<<dists[0]<<endl;
 //   scalars->SetValue(idx1,d);     //设置三角化后图像的属性值
    if (d>maxDistance) maxDistance = d;
  }
/*
  cube->GetPointData()->SetScalars(scalars);
  writer->SetFileName("segauto-asd.vtk");
  #if VTK_MAJOR_VERSION <= 5
    writer->SetInput(cube);
  #else
    writer->SetInputData(cube);
  #endif
    writer->Write();
*/
 for(unsigned int idx2=0; idx2<numBorderPts; idx2++) {
    borderTree1->annkSearch( borderPts2[idx2], 1, nnIdx, dists);
    avgSqrDistance += dists[0];
    double d = sqrt( dists[0] );
    avgDistance += d;
    scalars->SetValue(idx2,d);     //设置三角化后图像的属性值
    if (d>maxDistance) maxDistance = d;
  }

  cube->GetPointData()->SetScalars(scalars);
  writer->SetFileName("glodstand-asd-2.vtk");
  #if VTK_MAJOR_VERSION <= 5
    writer->SetInput(cube);
  #else
    writer->SetInputData(cube);
  #endif
    writer->Write();

double allnum = numBorderPts*2;
double avg = avgDistance/allnum;
  cout<<avg<<endl;
  return EXIT_SUCCESS;
}
