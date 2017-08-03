/*=========================================================================
 
   Program:   Visualization Toolkit
   Module:    $RCSfile: vtkDataSetToImageFilter.h,v $
  Language:  C++
 
   Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
   All rights reserved.
   See Copyright.txt or http://www.kitware.com/Copyright.htm for details.
 
      This software is distributed WITHOUT ANY WARRANTY; without even 
      the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
      PURPOSE.  See the above copyright notice for more information.
 
 =========================================================================*/
 #ifndef __vtkDataSetToImageFilter_h
 #define __vtkDataSetToImageFilter_h
 
 //#include "vtkImageSource.h"
 
 class vtkDataSet;
 
 class VTK_FILTERING_EXPORT vtkDataSetToImageFilter : public vtkImageSource
 {
 public:
   vtkTypeRevisionMacro(vtkDataSetToImageFilter,vtkImageSource);
   void PrintSelf(ostream& os, vtkIndent indent);
 
 
  virtual void SetInput(vtkDataSet *input);
   vtkDataSet *GetInput();
   
 protected:
   vtkDataSetToImageFilter() {this->NumberOfRequiredInputs = 1;};
   ~vtkDataSetToImageFilter() {};
 
   // All the DataSetToImageFilters require all their input.
   void ComputeInputUpdateExtents(vtkDataObject *output);
 
 private:
   vtkDataSetToImageFilter(const vtkDataSetToImageFilter&);  // Not implemented.
   void operator=(const vtkDataSetToImageFilter&);  // Not implemented.
 };
 
 #endif
