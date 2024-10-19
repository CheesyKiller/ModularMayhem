@echo off

REM Check if the last command (build) was successful
IF %ERRORLEVEL%==0 (
    echo Build succeeded, proceeding with Git operations...

    REM Set up Git credential helper
    git config --global credential.helper manager
    IF %ERRORLEVEL% NEQ 0 (
        echo Failed to configure Git credential helper.
        exit /b 1
    )
    echo Git credential helper configured.

    REM Fetch from the remote repository
    git fetch https://github.com/CheesyKiller/ModularMayhem.git
    IF %ERRORLEVEL% NEQ 0 (
        echo Failed to fetch from origin.
        exit /b 1
    )
    echo Fetched from origin successfully.

    REM Reset the repository softly to upstream
    git reset --soft @{u}
    IF %ERRORLEVEL% NEQ 0 (
        echo Failed to reset to upstream.
        exit /b 1
    )
    echo Reset to upstream successfully.

    REM Commit the changes with a message
    git commit -m "Squashing all un-pushed commits after successful build"
    IF %ERRORLEVEL% NEQ 0 (
        echo Failed to commit changes.
        exit /b 1
    )
    echo Commit created successfully.

    REM Push the changes to the remote repository
    git push https://github.com/CheesyKiller/ModularMayhem.git master --force
    IF %ERRORLEVEL% NEQ 0 (
        echo Failed to push changes to the remote.
        exit /b 1
    )
    echo Pushed to the remote repository successfully.

    echo All Git operations completed successfully.
) ELSE (
    echo Build failed, skipping Git operations.
)