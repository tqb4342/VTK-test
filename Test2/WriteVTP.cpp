#include <vtkVersion.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPolyDataWriter.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkFloatArray.h>
#include <vtkPointData.h>
 
int main ( int, char *[] )
{
  // Create 10 points.
/*  vtkSmartPointer<vtkPoints> points = 
    vtkSmartPointer<vtkPoints>::New();
 
  for ( unsigned int i = 0; i < 10; ++i )
    {
    points->InsertNextPoint ( i, i, i );
    }
 
  // Create a polydata object and add the points to it.
  vtkSmartPointer<vtkPolyData> polydata = 
    vtkSmartPointer<vtkPolyData>::New();
  polydata->SetPoints(points);
 */

int i;
	//定义点在三维坐标系中的坐标
	static float x[8][3]={{0,0,0,},{1,0,0},{1,1,0},{0,1,0},{0,0,1},{1,0,1},{1,1,1},{0,1,1}};
	//定义单元(通过点的索引来表达点之间的关系，所以采用vtkIdType)
	static vtkIdType pts[6][4]={{0,1,2,3},{4,5,6,7},{0,1,5,4},{1,2,6,5},{2,3,7,6},{3,0,4,7}};

	vtkPolyData *cube=vtkPolyData::New();//创建数据集对象的实例
	vtkPoints *points=vtkPoints ::New();//创建vtkPoints对象的实例
	vtkCellArray *polys=vtkCellArray::New();

	for(i=0;i<8;i++)points->InsertPoint(i,x[i]);//将点坐标插入vtkPoints对象中
	for(i=0;i<6;i++)polys->InsertNextCell(4,pts[i]);//

	cube->SetPoints(points);//为数据集添加点，定义其几何
	points->Delete();
	cube->SetPolys(polys);//为数据集添加单元，定义其拓扑
	polys->Delete();

	vtkFloatArray *scalars=vtkFloatArray::New();

	 scalars->SetNumberOfValues(8);
	
	for(i=0;i<8;i++) scalars->SetValue(i,i+1);
	
	cube->GetPointData()->SetScalars(scalars);


  // Write the file
  vtkSmartPointer<vtkPolyDataWriter> writer =  
    vtkSmartPointer<vtkPolyDataWriter>::New();
  writer->SetFileName("test.vtk");
#if VTK_MAJOR_VERSION <= 5
  writer->SetInput(cube);
#else
  writer->SetInputData(cube);
#endif
 
  // Optional - set the mode. The default is binary.
  //writer->SetDataModeToBinary();
  //writer->SetDataModeToAscii();
 
  writer->Write();
 
  return EXIT_SUCCESS;
}
