# ModularMayhem
This is a modularized rendering engine... because I want to?

# Git for post-build visual studio auto-commit and push :D

~~~
REM Check if the build was successful
if %errorlevel% neq 0 exit 1

REM Change to the directory where your git repository is located (optional if you are already in the correct directory)
cd /d "$(SolutionDir)"

REM Stage changes
git add .

REM Commit changes with a message (you can customize the commit message)
git commit -m "Automated commit after successful build"

REM Push to the remote repository (replace 'origin' and 'main' with your remote and branch names)
git push https://github.com/CheesyKiller/ModularMayhem.git main
~~~

