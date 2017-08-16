#include <iostream>
#include <clang-c/Index.h>



using std::cout;
using std::endl;

void print_cursordetails(const CXCursor& c, const CXCursorKind& cursorkind )
{
    auto st = clang_getCursorKindSpelling(cursorkind);
    auto namestr = clang_getCursorSpelling(c);
        
    cout << "cursor: " << clang_getCString(namestr) << " of kind: " << clang_getCString(st) << endl;
        
    clang_disposeString(st);
    clang_disposeString(namestr);
};

int main(int argc, char** argv)
{
  cout << "libclang play..." << endl;
  
  auto index = clang_createIndex(0,0);
  auto unit = clang_parseTranslationUnit(index, "../../example_rttr_class.cpp", nullptr,0, nullptr,0,
                                         CXTranslationUnit_None);

  if(unit == nullptr)
  {
    cout << "unable to parse translation unit." << endl;
    return(-1);
  };
  
  auto cursor = clang_getTranslationUnitCursor(unit);
  
  
  clang_visitChildren(cursor,
      [] (CXCursor c, CXCursor parent, CXClientData client_data)
      {
        auto cursorkind = clang_getCursorKind(c);
        
        
        switch(cursorkind)
        {
            case(CXCursor_ClassDecl):
            case(CXCursor_CXXMethod):
            case(CXCursor_Constructor):
            case(CXCursor_Destructor):
            case(CXCursor_MacroInstantiation):
                print_cursordetails(c,cursorkind);
                break;
        
        };
                
        return CXChildVisit_Recurse;   
      }
  ,nullptr);               
                      
  
  
  clang_disposeTranslationUnit(unit);
  clang_disposeIndex(index);
  
  
};
