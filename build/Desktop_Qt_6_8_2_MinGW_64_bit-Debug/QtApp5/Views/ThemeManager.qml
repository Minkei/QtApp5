pragma Singleton
import QtQuick 2.15

QtObject {
    readonly property bool isDarkTheme: true // Property để switch theme

    // Dark Theme Colors
    readonly property var darkTheme: QtObject {
        readonly property color mainBackground: "#0F172A"

        // Panel Colors
        readonly property color panelBackgroundColor_Normal: "#1E293B"
        readonly property color panelBackgroundColor_Hovered: "#243548"
        readonly property color panelBackgroundColor_Actived: "#334155"
        readonly property color panelBorderColor_Normal: "#334155"
        readonly property color panelBorderColor_Hovered: "#475569"
        readonly property color panelBorderColor_Actived: "#64748B"

        // Button Colors
        readonly property color buttonColor_Normal: "#164E63"
        readonly property color buttonColor_Hovered: "#155E75"
        readonly property color buttonColor_Actived: "#0E7490"
        readonly property color buttonBorder_Normal: "#164E63"
        readonly property color buttonBorder_Hovered: "#155E75"
        readonly property color buttonBorder_Actived: "#0891B2"

        // Text Colors
        readonly property color textColor_Normal: "#E2E8F0"
        readonly property color textColor_Hovered: "#F1F5F9"
        readonly property color textColor_Actived: "#7DD3FC"
        readonly property color iconColor_Normal: "#CBD5E1"
        readonly property color iconColor_Hovered: "#E2E8F0"
        readonly property color iconColor_Actived: "#7DD3FC"

        // TextField Colors
        readonly property color textFieldBackgroundColor_Normal: "#1E293B"
        readonly property color textFieldBackgroundColor_Hovered: "#334155"
        readonly property color textFieldBackgroundColor_Actived: "#475569"
        readonly property color textFieldBorderColor_Normal: "#475569"
        readonly property color textFieldBorderColor_Hovered: "#64748B"
        readonly property color textFieldBorderColor_Actived: "#94A3B8"
        readonly property color textFieldTextColor_Normal: "#E2E8F0"
        readonly property color textFieldTextColor_Hovered: "#F1F5F9"
        readonly property color textFieldTextColor_Actived: "#7DD3FC"
    }

    // lightTheme Theme Colors
    readonly property var lightTheme: QtObject {
        readonly property color mainBackground: "#F8FAFC"

        // Panel Colors
        readonly property color panelBackgroundColor_Normal: "#FFFFFF"
        readonly property color panelBackgroundColor_Hovered: "#F1F5F9"
        readonly property color panelBackgroundColor_Actived: "#E2E8F0"
        readonly property color panelBorderColor_Normal: "#E2E8F0"
        readonly property color panelBorderColor_Hovered: "#CBD5E1"
        readonly property color panelBorderColor_Actived: "#94A3B8"

        // Button Colors
        readonly property color buttonColor_Normal: "#0D9488"
        readonly property color buttonColor_Hovered: "#14B8A6"
        readonly property color buttonColor_Actived: "#2DD4BF"
        readonly property color buttonBorder_Normal: "#0D9488"
        readonly property color buttonBorder_Hovered: "#14B8A6"
        readonly property color buttonBorder_Actived: "#2DD4BF"

        // Text Colors
        readonly property color textColor_Normal: "#334155"
        readonly property color textColor_Hovered: "#1E293B"
        readonly property color textColor_Actived: "#0F172A"
        readonly property color iconColor_Normal: "#475569"
        readonly property color iconColor_Hovered: "#334155"
        readonly property color iconColor_Actived: "#1E293B"

        // TextField Colors
        readonly property color textFieldBackgroundColor_Normal: "#FFFFFF"
        readonly property color textFieldBackgroundColor_Hovered: "#F8FAFC"
        readonly property color textFieldBackgroundColor_Actived: "#F1F5F9"
        readonly property color textFieldBorderColor_Normal: "#CBD5E1"
        readonly property color textFieldBorderColor_Hovered: "#94A3B8"
        readonly property color textFieldBorderColor_Actived: "#64748B"
        readonly property color textFieldTextColor_Normal: "#334155"
        readonly property color textFieldTextColor_Hovered: "#1E293B"
        readonly property color textFieldTextColor_Actived: "#0F172A"
    }

    // Active theme based on isDarkTheme
    readonly property var current: isDarkTheme ? darkTheme : lightTheme
}
