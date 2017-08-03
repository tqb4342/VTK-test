#include <iostream>
using namespace std;

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"


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
//#include < vtkImagePointDataIterator.h >


int main(int argc,char* argv[])
{
	
 	vtkSmartPointer<vtkPolyDataReader > vtkreader=vtkSmartPointer<vtkPolyDataReader >::New();

	vtkreader->SetFileName(argv[1]);

	vtkreader->Update();

	vtkPolyData *cube = vtkreader->GetOutput();
	int dims[3];
	vtkreader->GetOutput()->GetDimensions(dims);
/*
const unsigned int Dimension = 3; //定义图像维数
	typedef unsigned char PixelType;  //定义像素类型
	typedef itk::Image< PixelType,Dimension > ImageType;
	typedef itk::ImageFileReader< ImageType > ReaderType;
	//typedef itk::ImageFileWriter< ImageType > WriterType;

	ReaderType::Pointer reader = ReaderType::New();
	reader->SetFileName(argv[1]);
	reader->Update();

	ImageType::Pointer image = reader->GetOutput();

	//2、定义迭代器,需要给定图像指针和需要访问的图像区域大小
	typedef itk::ImageRegionIterator<ImageType> ItType; 
	ItType it( image, image->GetRequestedRegion() );
	//3、将迭代器移动到首个元素
	it.GoToBegin();
	//4、遍历像素,直至结束
	cout<<"开始啦！"<<endl;
	while( !it.IsAtEnd() )
	{
		
	//5、获取像素值
	ImageType::PixelType vlaue = it.Get();
	cout<<(int)vlaue<<" ";
	//6、重新设置像素值
	//it.Set( 255 );

	//7、迭代器移动至下一元素
	++it;
	}
*/
	return 0;
}
