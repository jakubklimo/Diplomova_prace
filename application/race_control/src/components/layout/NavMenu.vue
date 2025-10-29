<template>
    <nav class="flex flex-col gap-3">
        <RouterLink
            v-for="link in links"
            :key="link.to"
            :to="link.to"
            class="flex items-center gap-2 p-2 rounded hover:bg-gray-700"
            :class="ui.isSidebarCollapsed ? 'justify-center' : ''"
            active-class="bg-gray-800"
        >
            <svg class="w-5 h-5 text-white">
                <use :href="link.icon" />
            </svg>
            <span v-if="!ui.isSidebarCollapsed">{{ t(link.label) }}</span>
        </RouterLink>
    </nav>
</template>

<script setup lang="ts">
import { useI18n } from 'vue-i18n';
import { useUiStore } from '../../store';

const { t } = useI18n();
const ui = useUiStore();

const links = [
    { to: '/', label: 'sidebar.dashboard', icon: '#icon-dashboard' },
    { to: '/settings', label: 'sidebar.settings', icon: '#icon-settings' },
]
</script>