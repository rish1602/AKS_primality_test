# AKS_primality_test
This project implements “AKS Primality test”- Dynamic Link Library DLL using it as header for the clients app using C++17

**What is Dynamic Link Library**
=>	In Windows, a dynamic-link library (DLL) is a kind of executable file that acts as a shared library of functions and resources. Dynamic linking is an operating system capability. It enables an executable to call functions or use resources stored in a separate file. These functions and resources can be compiled and deployed separately from the executables that use them.

=> A DLL isn't a stand-alone executable. DLLs run in the context of the applications that call them. The operating system loads the DLL into an application's memory space. It's done either when the application is loaded (implicit linking), or on demand at runtime (explicit linking). DLLs also make it easy to share functions and resources across executables. Multiple applications can access the contents of a single copy of a DLL in memory at the same time.

**Difference between dynamic and static linking**
=>	Static linking copies all the object code in a static library into the executables that use it when they're built. Dynamic linking includes only the information needed by Windows at run time to locate and load the DLL that contains a data item or function. When you create a DLL, you also create an import library that contains this information. When you build an executable that calls the DLL, the linker uses the exported symbols in the import library to store this information for the Windows loader. When the loader loads a DLL, the DLL is mapped into the memory space of your application. If present, a special function in the DLL, DllMain, is called to do any initialization the DLL requires.


**Walkthrough of the project**
=>	Like a statically linked library, a DLL exports variables, functions, and resources by name. A client app imports the names to use those variables, functions, and resources. Unlike a statically linked library, Windows connects the imports in your app to the exports in a DLL at load time or at run time, instead of connecting them at link time.

=>	This walkthrough creates two Visual Studio solutions; one that builds the DLL, and one that builds the client app. The DLL uses the C calling convention. It can be called from apps written in other programming languages, as long as the platform, calling conventions, and linking conventions match. The client app uses implicit linking, where Windows links the app to the DLL at load-time. This linking lets the app call the DLL-supplied functions just like the functions in a statically linked library.


=>	Even though the code of the DLL is written in C++, we've used C-style interfaces for the exported functions. There are two main reasons for this: First, many other languages support imports of C-style functions. The client app doesn't have to be written in C++. Second, it avoids some common pitfalls related to exported classes and member functions. It's easy to make hard-to-diagnose errors when exporting classes, since everything referred to within a class declaration has to have an instantiation that's also exported. This restriction applies to DLLs, but not static libraries. If your classes are plain-old-data style, you shouldn't run into this issue.

**Prerequisites**
=>	We have used Microsoft Visual Studio and ensured that “Desktop development with C++” is checked at time of installation.

**Steps**
**1.	Creating DLL**
=>	On the menu bar, choose File > New > Project to open the Create a New Project dialog box.
=>	At the top of the dialog, set Language to C++, set Platform to Windows, and set Project type to Library.
=>	From the filtered list of project types, select Dynamic-link Library (DLL), and then choose Next.
=>	In the Configure your new project page, enter AKSLibrary in the Project name box to specify a name for the project. Leave the default Location and Solution name values. Set Solution to Create new solution. Uncheck Place solution and project in the same directory if it's checked.
=>	Choose the Create button to create the project. When the solution is created, you can see the generated project and source files in the Solution Explorer window in Visual Studio.

**2.	Adding header to DLL**
=>	To create a header file for your functions, on the menu bar, choose Project > Add New Item.
=>	In the Add New Item dialog box, in the left pane, select Visual C++. In the center pane, select Header File (.h). Specify AKSLibrary.h as the name for the header file.
=>	To create a header file for your functions, on the menu bar, choose Project > Add New Item.
=>	In the Add New Item dialog box, in the left pane, select Visual C++. In the center pane, select Header File (.h). Specify AKSLibrary.h as the name for the header file.
=>	Write header file code.

**3.	Adding implementation of DLL**
=>	To create a header file for your functions, on the menu bar, choose Project > Add New Item.
=>	In the Add New Item dialog box, in the left pane, select Visual C++. In the center pane, select Header File (.h). Specify AKSLibrary.h as the name for the header file.
=>	In the editor write the implementational code for AKSLibrary.

**To verify that everything works so far, compile the dynamic link library. To compile, choose Build > Build Solution on the menu bar. The DLL and related compiler output are placed in a folder called Debug directly below the solution folder. The output should look something like this:** 


**4.	Creating client’s application that uses DLL**
=>	When you create a DLL, think about how client apps may use it. To call the functions or access the data exported by a DLL, client source code must have the declarations available at compile time. At link time, the linker requires information to resolve the function calls or data accesses. A DLL supplies this information in an import library, a file that contains information about how to find the functions and data, instead of the actual code. And at run time, the DLL must be available to the client, in a location that the operating system can find.
=>	To avoid out-of-sync code, we recommend you three things to do-
•	In Client’s application, set “ADDITIONAL INCLUDE DIRECTORIES” to DLL original header file.
•	In Client’s application include path of DLL import library.
•	Copy DLL file to the client’s application project location. 

=>	On the menu bar, choose File > New > Project to open the Create a new project dialog box.
=>	At the top of the dialog, set Language to C++, set Platform to Windows, and set Project type to Console.
=>	From the filtered list of project types, choose Console App then choose Next.
=>	In the Configure your new project page, enter AKSClient in the Project name box to specify a name for the project. Leave the default Location and Solution name values. Set Solution to Create new solution. Uncheck Place solution and project in the same directory if it's checked.




**5.	Adding DLL header to include path (steps to do 1st bullet from above yellow box)**
=>	Right-click on the AKSClient node in Solution Explorer to open the Property Pages dialog.
=>	In the Configuration drop-down box, select All Configurations if it's not already selected.
=>	In the left pane, select Configuration Properties > C/C++ > General.
=>	In the property pane, select the drop-down control next to the Additional Include Directories edit box, and then choose Edit. Double-click in the top pane of the Additional Include Directories dialog box to enable an edit control. Or, choose the folder icon to create a new entry.
=>	In the edit control, specify the path to the location of the AKSLibrary.h header file. You can choose the ellipsis (...) control to browse to the correct folder.
=>	You can also enter a relative path from your client source files to the folder that contains the DLL header files. If you followed the directions to put your client project in a separate solution from the DLL, the relative path should look like this:
..\..\AKSLibrary\AKSLibrary
=>	If your DLL and client projects are in the same solution, the relative path might look like this:
..\AKSLibrary
=>	When the DLL and client projects are in other folders, adjust the relative path to match. Or, use the ellipsis control to browse for the folder.
=>	After you've entered the path to the header file in the Additional Include Directories dialog box, choose the OK button. In the Property Pages dialog box, choose the OK button to save your changes.

**6.	Adding import library to the clients project (steps to do 2nd bullet from above yellow box)**
=>	Right-click on the AKSClient node in Solution Explorer and choose Properties to open the Property Pages dialog.
=>	In the Configuration drop-down box, select All Configurations if it's not already selected. It ensures that any property changes apply to both Debug and Release builds.
=>	In the left pane, select Configuration Properties > Linker > Input. In the property pane, select the drop-down control next to the Additional Dependencies edit box, and then choose Edit. 
=>	In the Additional Dependencies dialog, add AKSLibrary.lib to the list in the top edit control.
=>	Choose OK to go back to the Property Pages dialog box.
=>	In the left pane, select Configuration Properties > Linker > General. In the property pane, select the drop-down control next to the Additional Library Directories edit box, and then choose Edit.
=>	Double-click in the top pane of the Additional Library Directories dialog box to enable an edit control. In the edit control, specify the path to the location of the AKSLibrary.lib file. By default, it's in a folder called Debug directly under the DLL solution folder. If you create a release build, the file is placed in a folder called Release. You can use the $(IntDir) macro so that the linker can find your DLL, no matter which kind of build you create. If you followed the directions to put your client project in a separate solution from the DLL project, the relative path should look like this:
                 ..\..\AKSLibrary\$(IntDir)
=>	If your DLL and client projects are in other locations, adjust the relative path to match. Once you've entered the path to the library file in the Additional Library Directories dialog box, choose the OK button to go back to the Property Pages dialog box. Choose OK to save the property changes.

**7.	Copy DLL to the same clients project location/ copy DLL in post-build event (steps to do 3rd bullet from above yellow box)**
=>	Right-click on the AKSClient node in Solution Explorer and choose Properties to open the Property Pages dialog.
=>	In the Configuration drop-down box, select All Configurations if it isn't already selected.
=>	In the left pane, select Configuration Properties > Build Events > Post-Build Event.
=>	In the property pane, select the edit control in the Command Line field. If you followed the directions to put your client project in a separate solution from the DLL project, then enter this command:
xcopy /y /d "..\..\AKSLibrary\$(IntDir)AKSLibrary.dll" "$(OutDir)"
=>	If your DLL and client projects are in other directories, change the relative path to the DLL to match.

