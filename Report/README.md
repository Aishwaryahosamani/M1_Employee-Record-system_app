 ## Requirements


  ## High level requirements

  
   * HLR01             Adding the employee details
   * HLR02             Searching the employee details
   * HLR03             Deleting the  existing employee details
   * HLR04             Update the username and password
   * HLR05             View the employee details
  ## Low level requirements

   * LLR01              Add the employee  id,employee   name,father name,date of joining. 
   * LLR02             Search the employee   details by using their employee   id.
   * LLR03             Delete the employee   details by using their employee   id.
   * LLR04              Update the existing password and username into new password and username.


![swot analysis](https://user-images.githubusercontent.com/46986941/155399416-d8cfb77f-df8e-48ac-bafa-fd6872ac64f5.png)
09fc5e0d6.png)


  ## 5W and 1H

   * WHAT 
       To manage the employee records.
   
   * WHERE 
       Companies,industries,government offices,etc...
  
   * WHEN 
   
       Whenever we need to add/delete/update the details.
   * WHY 
       To manage the features of the record
   
   * WHO 
       Employes,admin,other office members
   
   * HOW 
      Digital mode
      
    # Architecture
    
    * Behavioral 
    
    Activity diagram
    
    ![activity diagram](https://user-images.githubusercontent.com/46986941/155399393-4b666a94-6ada-4a85-aa91-38a355ee123a.png)

 Use case diagram
 
 
  ![USE CASE](https://user-images.githubusercontent.com/46986941/155399398-95488960-7ee6-4bda-b70c-ff3

   * Structural diagram
     
     class diagram
      
      ![class](https://user-images.githubusercontent.com/46986941/155399230-7adfd395-30e5-4dcf-b2b3-846cd2032ab2.png)
      
     component diagram
     
     ![component diagram ](https://user-images.githubusercontent.com/46986941/155399249-78f80d19-0d4f-49b6-9f1b-e43a0233d57a.png)

      
      
     # Test Plan

|Test ID   |Test Case objective  |Input data   |Expected output   |Actual  output|
|----------|---------------------|-------------|------------------|---------------|
|TC-01     |Login details        |username:EmployeeRecord  and password :EmployeeRecord|login successfully|login successfully|
|TC_02   |For adding Employee details|Enter option 1 and fill the details|Added successfully|Added successfully|
|TC_03   |For searching Employee detais|employee Id  |Searched successfully|Searched successfully|
|TC_04|For viewing the Employee details |employee Id |Display the details|not showing|
|TC_05|For deleting the Employee details|employee Id |Record deleted successfully|Record deleted successfully|
|TC_06|For updating the Employee details|employee Id |Your password has been changed successfully|Your password has been changed successfully|
