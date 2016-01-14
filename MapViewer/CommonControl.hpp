#pragma once

#include <Windows.h>
#include <string>
#include <vector>
#include <map>
#include <functional>

class CommonControl
{
    friend LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    private:
        LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

        const HINSTANCE m_instance;
        const HWND m_window;
        const HFONT m_labelFont;
        const HFONT m_textBoxFont;

        std::map<int, HWND> m_controls;
        std::map<int, std::function<void()>> m_buttonHandlers;
        std::map<int, std::function<void(bool)>> m_checkboxHandlers;

    public:
        CommonControl(HWND window);

        // adding controls
        void AddLabel(const std::wstring &text, int x, int y, int width, int height);
        void AddTextBox(int id, const std::wstring &text, int x, int y, int width, int height);
        void AddComboBox(int id, const std::vector<std::wstring> &items, int x, int y, int width, int height);
        void AddButton(int id, const std::wstring &text, int x, int y, int width, int height, std::function<void()> handler);
        void AddCheckBox(int id, const std::wstring &text, int x, int y, int width, int height, bool checked, std::function<void (bool)> handler);

        const std::string GetText(int id) const;
};