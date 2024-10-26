@echo off

git status
IF%ERRORLEVEL NEQ 0 (
    echo Failed to get status
    exit /b 1
)

REM Set up Git credential helper
git config --global credential.helper manager
IF %ERRORLEVEL% NEQ 0 (
    echo Failed to configure Git credential helper.
    exit /b 2
)
echo Git credential helper configured.

REM Stage all changes
git add .
IF %ERRORLEVEL% NEQ 0 (
    echo Failed to stage changes.
    exit /b 3
)
echo Changes staged.

REM Commit the changes with a message
git commit -m "Automated build commit"
IF %ERRORLEVEL% NEQ 0 (
    echo Failed to commit changes.
    exit /b 4
)
echo Changes committed successfully.