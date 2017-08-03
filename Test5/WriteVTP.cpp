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

#include <vtkSmartPointer.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkImageData.h>
#include <vtkImageMapper3D.h>
#include <vtkImageCast.h>
#include <vtkMetaImageWriter.h>
#include <vtkMetaImageReader.h>
#include <vtkImageMandelbrotSource.h>
#include <vtkImageActor.h>
#include <vtkPolyData.h>
#include <vtkFloatArray.h>
#include <vtkPolyDataWriter.h>
#include <vtkPointData.h>

int main(int, char *[])
{
   std::string filePath = "subresult.mhd";

 // Create an image
   vtkSmartPointer<vtkMetaImageReader> reader = 
   vtkSmartPointer<vtkMetaImageReader>::New();
   reader->SetFileName(filePath.c_str());
   reader->Update();

 // Convert the image to a polydata
  vtkSmartPointer<vtkImageDataGeometryFilter> imageDataGeometryFilter = 
   vtkSmartPointer<vtkImageDataGeometryFilter>::New();
  imageDataGeometryFilter->SetInputConnection(reader->GetOutputPort());
  imageDataGeometryFilter->Update();
  vtkPolyData *cube = imageDataGeometryFilter->GetOutput();


	int npoint = 0 ;
	npoint= cube->GetNumberOfPoints();
	printf("%d\n",npoint);
   return 0;
}
