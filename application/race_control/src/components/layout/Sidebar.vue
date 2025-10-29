<template>
    <aside
        class="hidden md:flex flex-col h-screen bg-gray-900 text-white p-4 transition-all duration-300"
        :class="ui.isSidebarCollapsed ? 'w-20' : 'w-64'"
    >
        <div class="text-xl font-bold mb-6">Race Timer</div>

        <NavMenu />

        <div class="grow"></div>

        <div 
            class="flex justify-between"
            :class="ui.isSidebarCollapsed ? 'justify-center' : ''"
        >
            <button @click="ui.toggleSidebar()" class="p-1 hover:bg-gray-700 rounded">
                <svg class="w-5 h-5 text-white">
                    <use :href="ui.isSidebarCollapsed ? '#icon-sidebar-open' : '#icon-sidebar-close'" />
                </svg>
            </button>
            <span v-if="!ui.isSidebarCollapsed">v{{ version }}</span>
        </div>
    </aside>
</template>

<script setup lang="ts">
import NavMenu from './NavMenu.vue';
import { useUiStore } from '../../store';

const version = __APP_VERSION__;
const ui = useUiStore();
</script>