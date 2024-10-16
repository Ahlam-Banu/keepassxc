/*
 *  Copyright (C) 2023 KeePassXC Team <team@keepassxc.org>
 *  Copyright (C) 2016 Lennart Glauer <mail@lennart-glauer.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_APPKIT_H
#define KEEPASSX_APPKIT_H

#include <QColor>
#include <QObject>
#include <unistd.h>

class QWindow;

class AppKit : public QObject
{
    Q_OBJECT

public:
    AppKit(QObject* parent = nullptr);
    ~AppKit();

    pid_t lastActiveProcessId();
    pid_t activeProcessId();
    pid_t ownProcessId();
    bool activateProcess(pid_t pid);
    bool hideProcess(pid_t pid);
    bool isHidden(pid_t pid);
    bool isDarkMode();
    bool isStatusBarDark();
    bool enableAccessibility();
    bool enableScreenRecording();
    void toggleForegroundApp(bool foreground);
    void setWindowSecurity(QWindow* window, bool state);

signals:
    void userSwitched();
    void interfaceThemeChanged();

private:
    void* self;
};

#endif // KEEPASSX_APPKIT_H
