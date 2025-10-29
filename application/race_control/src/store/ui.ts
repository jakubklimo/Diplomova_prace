import { defineStore } from "pinia";

export const useUiStore = defineStore('ui', {
    state: () => ({
        isMenuOpen: false,
        isSidebarCollapsed: false,
    }),
    actions: {
        toggleMenu() {
            this.isMenuOpen = !this.isMenuOpen;
            if (this.isMenuOpen) this.isSidebarCollapsed = false;
        },
        closeMenu() {
            this.isMenuOpen = false;
        },
        toggleSidebar() {
            this.isSidebarCollapsed = !this.isSidebarCollapsed;
        },
    } 
});