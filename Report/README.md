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
      
      
     # Test Plan

|Test ID   |Test Case objective  |Input data   |Expected output   |Actual  output|
|----------|---------------------|-------------|------------------|---------------|
|TC-01     |Login details        |username:EmployeeRecord  and password :EmployeeRecord|login successfully|login successfully|
|TC_02   |For adding Employee details|Enter option 1 and fill the details|Added successfully|Added successfully|
|TC_03   |For searching Employee detais|employee Id  |Searched successfully|Searched successfully|
|TC_04|For viewing the Employee details |employee Id |Display the details|not showing|
|TC_05|For deleting the Employee details|employee Id |Record deleted successfully|Record deleted successfully|
|TC_06|For updating the Employee details|employee Id |Your password has been changed successfully|Your password has been changed successfully|
