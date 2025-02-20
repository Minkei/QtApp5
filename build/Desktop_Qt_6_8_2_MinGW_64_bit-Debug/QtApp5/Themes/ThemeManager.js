.pragma library

// Theme state
var isDarkTheme = false;

// Dark Theme Colors
var darkTheme = {
    mainBackground: "#0F172A",

    // Panel Colors
    panelBackgroundColor_Normal: "#1E293B",
    panelBackgroundColor_Hovered: "#243548",
    panelBackgroundColor_Actived: "#334155",
    panelBorderColor_Normal: "#334155",
    panelBorderColor_Hovered: "#475569",
    panelBorderColor_Actived: "#64748B",

    // Button Colors
    buttonColor_Normal: "#164E63",
    buttonColor_Hovered: "#155E75",
    buttonColor_Actived: "#0E7490",
    buttonBorder_Normal: "#164E63",
    buttonBorder_Hovered: "#155E75",
    buttonBorder_Actived: "#0891B2",

    // Text Colors
    textColor_Normal: "#E2E8F0",
    textColor_Hovered: "#F1F5F9",
    textColor_Actived: "#7DD3FC",
    iconColor_Normal: "#CBD5E1",
    iconColor_Hovered: "#E2E8F0",
    iconColor_Actived: "#7DD3FC",

    // TextField Colors
    textFieldBackgroundColor_Normal: "#1E293B",
    textFieldBackgroundColor_Hovered: "#334155",
    textFieldBackgroundColor_Actived: "#475569",
    textFieldBorderColor_Normal: "#475569",
    textFieldBorderColor_Hovered: "#64748B",
    textFieldBorderColor_Actived: "#94A3B8",
    textFieldTextColor_Normal: "#E2E8F0",
    textFieldTextColor_Hovered: "#F1F5F9",
    textFieldTextColor_Actived: "#7DD3FC"
};

// Light Theme Colors
var lightTheme = {
    mainBackground: "#F8FAFC",

    // Panel Colors
    panelBackgroundColor_Normal: "#FFFFFF",
    panelBackgroundColor_Hovered: "#F8FAFC",
    panelBackgroundColor_Actived: "#F1F5F9",
    panelBorderColor_Normal: "#E2E8F0",
    panelBorderColor_Hovered: "#CBD5E1",
    panelBorderColor_Actived: "#94A3B8",

    // Button Colors - Sky tone
    buttonColor_Normal: "#0EA5E9",    // Sky-500
    buttonColor_Hovered: "#38BDF8",   // Sky-400
    buttonColor_Actived: "#0284C7",   // Sky-600
    buttonBorder_Normal: "#10B981",
    buttonBorder_Hovered: "#34D399",
    buttonBorder_Actived: "#059669",

    // Text Colors
    textColor_Normal: "#1E293B",      // Slate-800
    textColor_Hovered: "#0F172A",     // Slate-900
    textColor_Actived: "#10B981",     // Emerald-500 (đổi màu active theo button)
    iconColor_Normal: "#475569",      // Slate-600
    iconColor_Hovered: "#334155",     // Slate-700
    iconColor_Actived: "#10B981",     // Emerald-500

    // TextField Colors
    textFieldBackgroundColor_Normal: "#FFFFFF",
    textFieldBackgroundColor_Hovered: "#F8FAFC",
    textFieldBackgroundColor_Actived: "#F1F5F9",
    textFieldBorderColor_Normal: "#E2E8F0",    // Slate-200
    textFieldBorderColor_Hovered: "#CBD5E1",   // Slate-300
    textFieldBorderColor_Actived: "#10B981",   // Emerald-500
    textFieldTextColor_Normal: "#1E293B",      // Slate-800
    textFieldTextColor_Hovered: "#0F172A",     // Slate-900
    textFieldTextColor_Actived: "#10B981"      // Emerald-500
};

// Get current theme
function getCurrentTheme() {
    return isDarkTheme ? darkTheme : lightTheme;
}

// Toggle theme function
function toggleTheme() {
    isDarkTheme = !isDarkTheme;
    return getCurrentTheme();
}

// Export current theme
var current = getCurrentTheme();
