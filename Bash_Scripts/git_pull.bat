@echo off

REM Set up Git credential helper
git config --global credential.helper manager
IF %ERRORLEVEL% NEQ 0 (
    echo Failed to configure Git credential helper. Exit code: %ERRORLEVEL%
    exit /b %ERRORLEVEL%
)
echo Git credential helper configured.

REM Pull changes from the remote repository
git pull --set-upstream https://github.com/CheesyKiller/ModularMayhem.git master
IF %ERRORLEVEL% NEQ 0 (
    echo Failed to pull changes from the remote repository. Exit code: %ERRORLEVEL%
    exit /b %ERRORLEVEL%
)
echo Successfully pulled changes from the remote repository.